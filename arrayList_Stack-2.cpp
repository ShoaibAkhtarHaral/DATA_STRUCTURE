#include <iostream>
using namespace std;

class stack
{
    int top;
    int *arr;
    int capacity;

public:
    stack(int s)
    {
        capacity = s;
        arr = new int[s];
        top = -1;
    }

    bool isFull()
    {
        if (capacity == top + 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }

        else
        {
            return false;
        }
    }

    void push(int val)
    {
        if (!isFull())
        {
            top++;
            arr[top] = val;
        }

        else
        {
            cout << "Stack overFlow" << endl;
            return;
        }
    }

    void pop()
    {
        if (!isEmpty())
        {
            top--;
        }
        else
        {
            cout << "Stack underFlow" << endl;
        }
    }

    int peak()
    {
        if (!isEmpty())
        {
            int val = arr[top];
            return val;
        }
        return -1;
    }

    int greater()
    {
        int max = arr[top];
        for (int i = 0; i <= top; i++)
        {
            if (max < arr[i])
            {
                max = arr[i];
            }
        }
        return max;
    }

    void sortAssending()
    {

        for (int i = 0; i <= top; i++)
        {
            for (int j = i + 1; j <= top; j++)
            {
                if (arr[i] > arr[j])
                {
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }

    void display()
    {
        if (!isEmpty())
        {
            for (int i = 0; i <= top; i++)
            {
                cout << arr[i] << " ";
            }
        }
    }
};
int main()
{
    stack s(5);
    s.push(4);
    s.push(3);
    s.push(9);
    s.push(7);
    s.push(1);
    s.display();
    cout << "Get value: " << s.peak() << endl;
    s.pop();
    s.display();

    cout << "Max is: " << s.greater() << endl;
    s.sortAssending();
    s.display();
    return 0;
}
