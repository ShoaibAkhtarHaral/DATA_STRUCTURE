#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int n)
    {
        data = n;
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
        if (!isEmpty())
        {
            node *current = head;
            while (current->next != head)
            {
                node *temp = current;
                current = current->next;
                delete temp;
            }
            delete current; // Delete the last node
        }
    }

    bool isEmpty()
    {
        if (length == 0)
        {
            return true;
        }

        else
        {
            return false;
        }
    }

    void insert(int val, int pos)
    {
        if (pos < 1 || pos > length + 1)
        {
            cout << "invalid position" << endl;
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

    void remove(int pos)
    {
        if (isEmpty())
        {
            cout << "EMPTY" << endl;
            return;
        }

        if (pos == 1)
        {
            node *curr = head;
            node *temp = head;
            while (curr->next != head)
            {
                curr = curr->next;
            }

            curr->next = temp->next;
            head = temp->next;
            delete temp;
        }

        else
        {
            node *curr = head;
            node *slow = NULL;
            for (int i = 1; i < pos; i++)
            {
                slow = curr;
                curr = curr->next;
            }

            slow->next = curr->next;
            delete curr;
        }
        length--;
    }

    int odd()
    {
        int count = 0;
        if (!isEmpty())
        {

            node *temp = head;
            do
            {
                if (temp->data % 2 != 0)
                {
                    count++;
                }
                temp = temp->next;
            } while (temp != head);
        }
        return count;
    }

    int findMax()
    {
        int max = 0;
        if (!isEmpty())
        {

            for (int i = 1; i < length; i++)
            {
                node *temp = head;
                for (int j = 1; j < length; j++)
                {
                    if (temp->data > temp->next->data)
                    {
                        max = temp->data;
                    }
                    temp = temp->next;
                }
            }
        }
        return max;
    }

    void clear()
    {
        while (!isEmpty())
            remove(1);
    }

    int find(int val)
    {
        int pos = 1;
        node *curr = head;
        do
        {
            if (curr->data == val)
                return pos;
            curr = curr->next;
            pos++;
        } while (curr != head);

        return -1; // Value not found
    }

    void reverse()
    {
        if (!isEmpty())
        {
            node *prev = NULL;
            node *current = head;
            node *nextNode = NULL;
            do
            {
                nextNode = current->next;
                current->next = prev;
                prev = current;
                current = nextNode;
            } while (current != head);

            head = prev;
        }
    }

    void display()
    {
        node *temp = head;
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

int main()
{
    circularLinkedList c;
    c.insert(4, 1);
    c.insert(6, 2);
    c.insert(9, 3);
    c.insert(1, 4);
    c.insert(7, 3);
    c.display();
    c.remove(2);
    c.display();
    cout << "Odd is: " << c.odd() << endl;
    cout << "Maximum is: " << c.findMax() << endl;

    return 0;
}
