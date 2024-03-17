#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int v)
    {
        data = v;
        next = NULL;
    }
};

class circularLinkedList
{
private:
    int length;
    node *head;

public:
    circularLinkedList()
    {
        length = 0;
        head = NULL;
    }

    ~circularLinkedList()
    {
        if (head != NULL)
        {
            node *curr = head;
            do
            {
                node *temp = curr;
                curr = curr->next;
                delete temp;
            } while (curr != head);
        }
    }

    void insert(int val, int pos)
    {
        if (pos < 1 || pos > length + 1)
        {
            cout << "POsition not valid" << endl;
            return;
        }

        node *n = new node(val);
        node *curr = head;
        if (head == NULL)
        {
            head = n;
            n->next = head;
        }

        else if (pos == 1)
        {
            n->next = head;
            while (curr != head)
            {
                curr = curr->next;
            }

            curr->next = n;
            head = n;
        }

        else
        {
            for (int i = 1; i < pos - 1; i++)
            {
                curr = curr->next;
            }

            n->next = curr->next;
            curr->next = n;
        }
        length++;
    }

    int josephus(int n, int m)
    {
        for (int i = 1; i <= n; i++)
        {
            insert(i, i);
        }

        node *prev = NULL;
        node *curr = head;

        while (curr->next != curr)
        {
            if (m == 1)
            {
                prev = curr;
                curr = curr->next;
                prev->next = curr->next;
                if (curr == head)
                {
                    head = curr->next;
                }
                delete curr;
                curr = prev->next;
            }
            else
            {
                for (int i = 1; i <= m; i++)
                {
                    prev = curr;
                    curr = curr->next;
                }

                prev->next = curr->next;

                if (curr == head)
                {
                    head = curr->next;
                }

                delete curr;
                curr = prev->next;
            }
            length--;
        }

        return curr->data;
    }
};

int main()
{
    circularLinkedList c;
    int n, m;
    cout << "Enter the number of people: ";
    cin >> n;
    cout << "Enter The step size for counting: ";
    cin >> m;
    cout << "Last person remaining: " << c.josephus(n, m) << endl;

    return 0;
}