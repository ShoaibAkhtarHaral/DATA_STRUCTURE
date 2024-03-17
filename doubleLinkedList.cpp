#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node *prev;

    node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

class doubleLinkedList
{
private:
    node *head;
    int length;

public:
    doubleLinkedList()
    {
        head = NULL;
        length = 0;
    }

    void insert(int val, int pos)
    {
        if (pos < 1 || pos > length + 1)
        {
            cout << "Inlvaid position" << endl;
            return;
        }

        node *n = new node(val);

        if (pos == 1)
        {
            n->next = head;
            if (head != NULL)
                head->prev = n;
            head = n;
        }

        else
        {
            node *curr = head;
            for (int i = 1; i < pos - 1; i++)
            {
                curr = curr->next;
            }

            n->prev = curr;
            n->next = curr->next;
            if (curr->next != NULL)
                curr->next->prev = n;
            curr->next = n;
        }
        length++;
    }

    void remove(int pos)
    {
        if (length == 0)
        {
            cout << "EMPTY" << endl;
            return;
        }

        if (pos < 1 || pos > length)
        {
            cout << "position not valid" << endl;
            return;
        }

        node *n = head;
        if (pos == 1)
        {
            head = head->next;
            delete n;
            if (head != NULL)
                head->prev = NULL;
        }

        else
        {
            node *slow = NULL;
            for (int i = 1; i < pos; i++)
            {
                slow = n;
                n = n->next;
            }

            slow->next = n->next;
            if (n->next != NULL)
                n->next->prev = slow;

            delete n;
        }

        length--;
    }

    bool palindrome()
    {
        if (isEmpty())
        {
            return false;
        }

        else
        {
            node *curr = head;
            node *last = head;
            while (last->next != NULL)
            {
                last = last->next;
            }

            for (int i = 0; i < length / 2; i++)
            {
                if (curr->data != last->data)
                {
                    return false;
                }
                curr = curr->next;
                last = last->prev;
            }
            return true;
        }
    }
    void sortAssending()
    {
        for (int i = 0; i < length - 1; i++)
        {
            node *n = head;
            for (int j = 0; j < length - i - 1; j++)
            {
                if (n->data > n->next->data)
                {
                    int temp = n->data;
                    n->data = n->next->data;
                    n->next->data = temp;
                }
                n = n->next;
            }
        }
    }

    int search(int val)
    {
        int pos = 1;
        node *curr = head;
        while (curr != NULL)
        {
            if (curr->data == val)
            {
                return pos;
            }
            curr = curr->next;
            pos++;
        }
        return -1; // Value not found
    }

    void update(int newVal, int pos)
    {
        if (pos < 1 || pos > length)
        {
            cout << "Position not valid" << endl;
            return;
        }

        node *curr = head;
        for (int i = 1; i < pos; i++)
        {
            curr = curr->next;
        }

        curr->data = newVal;
    }

    int getLength()
    {
        return length;
    }

    void clear()
    {
        while (head != NULL)
        {
            node *temp = head;
            head = head->next;
            delete temp;
            length--;
        }
    }

    void reverse()
    {
        if (length <= 1)
        {
            return; // Nothing to reverse
        }

        node *curr = head;
        node *prev = NULL;
        node *nextNode = NULL;

        while (curr != NULL)
        {
            nextNode = curr->next;
            curr->next = prev;
            curr->prev = nextNode;

            prev = curr;
            curr = nextNode;
        }

        head = prev; // Update the head to the new first element
    }

    void insertNEW(int val)
    {
        node *n = new node(val);

        if (head == NULL || val < head->data)
        {
            // Insert at the beginning
            n->next = head;
            n->prev = head->prev;
            head->prev = n;
            head = n;

            length++;
            return;
        }

        node *curr = head;

        while (curr->next != NULL && val > curr->next->data)
        {
            curr = curr->next;
        }

        // Insert after curr
        n->next = curr->next;
        curr->next = n;
        n->prev = curr;
        length++;
    }

    void display()
    {
        node *n = head;
        while (n != NULL)
        {
            cout << n->data << " ";
            n = n->next;
        }
        cout << endl;
    }
};
int main()
{
    doubleLinkedList l;
    l.insert(4, 1);
    l.insert(7, 2);
    l.insert(5, 3);
    l.insert(1, 4);
    l.display();
    l.remove(4);
    l.display();
    l.insert(6, 4);
    l.display();
    l.sortAssending();
    l.display();
    l.insertNEW(10);
    l.display();
    l.reverse();
    l.display();
    return 0;
}
