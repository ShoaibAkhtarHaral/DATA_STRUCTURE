#include <iostream>
using namespace std;

class arrayList
{
    int *arr;
    int capacity, length;
    int *curr;

public:
    arrayList(int l)
    {
        capacity = l;
        arr = new int[l];
        length = 0;
        curr = arr;
    }

    ~arrayList()
    {
        delete[] arr;
    }

    void start()
    {
        curr = arr;
    }

    void back()
    {
        curr--;
    }

    void next()
    {
        curr++;
    }

    void tail()
    {
        curr = arr + length - 1;
    }

    bool isEmpty()
    {
        if (length == 0)
        {
            return true;
        }
        else
            return false;
    }

    bool isFull()
    {
        if (length == capacity)
        {
            return true;
        }
        else
            return false;
    }

    void insert(int val, int pos)
    {
        if (isFull())
        {
            cout << "List is Full" << endl;
            return;
        }

        if (pos < 1 || pos > length + 1)
        {
            cout << "Invalid Position" << endl;
            return;
        }

        else
        {
            tail();
            for (int i = length; i >= pos; i--)
            {
                *(curr + 1) = *curr;
                back();
            }

            *(curr + 1) = val;
            length++;
        }
    }

    void remove(int pos)
    {
        if (isEmpty())
        {
            cout << "List is empty" << endl;
            return;
        }

        if (pos < 1 || pos > length + 1)
        {
            cout << "Invalid Position" << endl;
            return;
        }

        start();
        curr = arr + pos - 1;
        for (int i = pos; i < length; i++)
        {
            *curr = *(curr + 1);
            next();
        }
        length--;
    }

    void print()
    {
        start();
        for (int i = 0; i < length; i++)
        {
            cout << *curr << " ";
            next();
        }
        cout << endl;
    }

    bool search(int val)
    {
        start();
        for (int i = 0; i < length; i++)
        {
            if (*curr == val)
            {
                return true;
            }
            next();
        }
        return false;
    }

    void reverse()
    {
        // reverse using array
        int s = 0;
        int l = length - 1; // Correcting the length of the array

        while (s < l)
        {
            // Swap elements at positions s and l
            int temp = arr[s];
            arr[s] = arr[l];
            arr[l] = temp;

            // Move the pointers towards each other
            s++;
            l--;
        }

        // reverse using pointers
        int *start = arr;
        int *end = arr + length - 1;

        while (start < end)
        {
            int temp = *start;
            *start = *end;
            *end = temp;
            start++;
            end--;
        }
    }

    void reverse(int k)
    {
        int s = 0;
        int l = k - 1; // Correcting the length of the array

        while (s < l)
        {
            // Swap elements at positions s and l
            int temp = arr[s];
            arr[s] = arr[l];
            arr[l] = temp;

            // Move the pointers towards each other
            s++;
            l--;
        }
    }

    void insertSorted(int val)
    {
        if (isFull())
        {
            cout << "List is Full" << endl;
            return;
        }
        sortingArray();
        start();
        int count = 0;
        while (count < length || val > *curr)
        {
            count++;
            next();
        }

        tail();
        for (int i = length; i > count; i--)
        {
            *(curr + 1) = *curr;
            back();
        }
        *(curr + 1) = val;
        length++;
    }

    void sortingArray()
    {
        start();
        for (int i = 0; i < length; i++)
        {
            start();
            for (int j = i + 1; j < length; j++)
            {
                if (*curr > *(curr + 1))
                {
                    int temp = *curr;
                    *curr = *(curr + 1);
                    *(curr + 1) = temp;
                    next();
                }
                start();
            }
        }
    }

    void update(int val, int pos)
    {
        if (pos < 1 || pos > length + 1)
        {
            cout << "Invalid position" << endl;
            return;
        }

        start();
        for (int i = 1; i < pos; i++)
        {
            next();
        }

        *curr = val;
    }

    void removeDublicates()
    {
        start();
        for (int i = 0; i < length; i++)
        {
            int current = *curr;
            for (int j = i + 1; j < length; j++)
            {
                if (current == arr[j])
                {
                    for (int k = j; k < length - 1; k++)
                    {
                        arr[k] = arr[k + 1];
                    }

                    length--;
                    j--;
                }
            }
            next();
        }
    }

    void shift(int shiftNo)
    {
        start();
        // for (int i = 0; i < length/2; i++)
        // {

        // }

        int *start = arr;
        int *end = arr + shiftNo;

        for (int i = 0; i < length/2; i++)
        // while (*end != length)

        {
            int temp = *start;
            *start = *end;
            *end = temp;
            start++;
            end++;
        }
    }
};

int main()
{
    arrayList l(6);
    l.insert(1, 1);
    l.insert(2, 2);
    l.insert(3, 3);
    l.insert(4, 4);
    l.print();
    if (l.search(6))
    {
        cout << "Value found" << endl;
    }
    else
    {
        cout << "Value not found" << endl;
    }
    l.reverse();
    l.print();
    l.reverse();
    l.print();
    // l.reverse(3);
    // l.print();
    l.insertSorted(5);
    l.insert(6,6);
    l.print();
    l.sortingArray();
    l.print();
    l.shift(2);
    l.print();

    // cout << "new insertion for remove dublicates" << endl;
    // arrayList l1(6);
    // l1.insert(1, 1);
    // l1.insert(2, 2);
    // l1.insert(3, 3);
    // l1.insert(5, 4);
    // l1.insert(3, 5);
    // l1.insert(2, 6);
    // l1.print();
    // l1.removeDublicates();
    // l1.print();

    return 0;
}