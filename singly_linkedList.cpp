#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int d)
    {
        data = d;
        next = NULL;
    }
};

class linkedList
{
    node *head;
    int length;

public:
    linkedList()
    {
        head = NULL;
        length = 0;
    }

    bool isEmpty()
    {
        if (head == NULL)
        {
            return true;
        }
        else
            return false;
    }

    void insert(int val, int pos)
    {
        if (pos < 1 || pos > length + 1)
        {
            cout << "Invalid Position" << endl;
            return;
        }

        node *n = new node(val);
        if (pos == 1)
        {
            n->next = head;
            head = n;
        }

        else
        {
            node *curr = head;
            for (int i = 1; i < pos - 1; i++)
            {
                curr = curr->next;
            }
            n->next = curr->next;
            curr->next = n;
        }

        length++;
    }

    void search(int val)
    {
        if (isEmpty())
        {
            cout << "List is empty" << endl;
            return;
        }

        node *temp = head;
        while (temp != NULL)
        {
            if (temp->data == val)
            {
                cout << val << " value found in list" << endl;
                return;
            }
            temp = temp->next;
        }
        cout << val << " value not found" << endl;
    }

    void reverse()
    {
        node *curr = head;
        node *prev = NULL;
        node *next = NULL;

        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    void remove(int pos)
    {
        if (isEmpty())
        {
            cout << "list is empty" << endl;
            return;
        }

        node *n = head;
        if (pos == 1)
        {
            head = n->next;
        }

        else
        {
            node *prev = NULL;
            for (int i = 1; i < pos; i++)
            {
                prev = n;
                n = n->next;
            }

            prev->next = n->next;
        }
        length--;
        delete n;
    }

    void singlyToCircular()
    {
        node *curr = head;
        while (curr->next != NULL)
        {
            curr = curr->next;
        }

        curr->next = head;
    }

    void display()
    {
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void checkCircular()
    {
        node *curr = head;
        int ch = 0;
        while (ch != 2)
        {
            cout << "\n1. next\n2. exit\n";
            cin >> ch;
            if (ch == 1)
            {
                cout << curr->data << " ";
                curr = curr->next;
            }
        }
        cout << endl;
    }

    void sorting()
    {
        if (isEmpty())
        {
            cout << "Lst is empty" << endl;
            return;
        }

        node *n = head;
        for (int i = 0; i < length; i++)
        {
            node *temp = n;
            temp = temp->next;
            for (int j = i + 1; j < length; j++)
            {
                if (n->data > temp->data)
                {
                    int t = temp->data;
                    temp->data = n->data;
                    n->data = t;
                }
                temp = temp->next;
            }
            n = n->next;
        }
    }

    int checkDublicate()
    {
        if (isEmpty())
        {
            cout << "Lst is empty" << endl;
            return -1;
        }
        int count = 0;

        node *n = head;
        for (int i = 0; i < length; i++)
        {
            node *temp = n;
            temp = temp->next;
            for (int j = i + 1; j < length; j++)
            {
                if (n->data == temp->data)
                {
                    count++;
                }
                temp = temp->next;
            }
            n = n->next;
        }
        return count;
    }

    bool checkPalindrome()
    {
        if (isEmpty())
        {
            cout << "Lst is empty" << endl;
            return false;
        }

        node *n = head;
        for (int i = 1; i <= length / 2; i++)
        {
            node *temp = head;

            for (int j = 1; j <= length - i; j++)
            {
                temp = temp->next;
            }
            if (temp->data != n->data)
            {
                return false;
            }
            n = n->next;
        }
        return true;
    }

    void insertSorted(int val)
    {
        sorting();
        node *n = head;
        node *prev = NULL;
        while (n != NULL)
        {
            if (n->data > val)
            {
                break;
            }
            prev = n;
            n = n->next;
        }

        node *newNode = new node(val);
        if (n == head)
        {
            newNode->next = n;
            head = newNode;
        }

        else
        {
            newNode->next = n;
            prev->next = newNode;
        }
        length++;
    }
};

int main()
{
    linkedList l;
    l.insert(4, 1);
    l.insert(1, 1);
    l.insert(7, 1);
    l.insert(10, 4);
    l.display();
    // l.search(11);
    cout << "Reverse: \n";
    l.reverse();
    l.display();
    // l.remove(1);
    // l.display();
    // l.singlyToCircular();
    // l.checkCircular();
    if (l.checkPalindrome())
    {
        cout << "List is palindrome\n";
    }
    else
        cout << "List NOT palindrome\n";
    cout << "\nSorting:\n";
    l.sorting();
    l.display();
    l.insertSorted(5);
    l.display();
    l.remove(1);
    l.display();
    l.insertSorted(2);
    l.display();
    l.insertSorted(20);
    l.display();
    int num = l.checkDublicate();
    cout << "Total Dublicate in list: " << num << endl;

    cout << endl;
    linkedList l2;
    cout << "Next list:\n";
    l2.insert(2, 1);
    l2.insert(4, 2);
    l2.insert(6, 3);
    l2.insert(4, 4);
    l2.insert(2, 5);
    l2.display();
    if (l2.checkPalindrome())
    {
        cout << "List is palindrome\n";
    }
    else
        cout << "List NOT palindrome\n";
    return 0;
}