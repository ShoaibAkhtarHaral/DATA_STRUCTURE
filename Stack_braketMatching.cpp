#include <iostream>
using namespace std;

class stack
{
    int top;
    char *arr;
    int capacity;

public:
    stack(int s)
    {
        capacity = s;
        arr = new char[s];
        top = -1;
    }

    ~stack()
    {
        delete[] arr;
    }

    bool isFull()
    {
        if (top + 1 == capacity)
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
        if (top + 1 == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void push(char val)
    {
        if (isFull())
        {
            cout << "Stack overFlow" << endl;
            return;
        }

        else
        {
            top++;
            arr[top] = val;
        }
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "stack underFlow" << endl;
            return -1;
        }

        else
        {
            char val = arr[top];
            top--;
            return val;
        }
    }
};

bool bracketCheck(string str)
{
    int length = str.length();
    stack bracketStack(length);

    for (int i = 0; i < length; i++)
    {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[')
        {
            bracketStack.push(str[i]);
        }

        else if (str[i] == ')' || str[i] == '}' || str[i] == ']')
        {
            if (bracketStack.isEmpty())
            {
                return false;
            }

            else
            {
                char top = bracketStack.pop();
                if ((str[i] == ')' && top != '(') || (str[i] == '}' && top != '{') || str[i] == ']' && top != '[')
                {
                    return false;
                }
            }
        }
    }
    return true;
}

int main()
{
    string str;
    str = "{[()]}";
    cout << "--------------------------------" << endl;
    cout << "Input is: " << str << endl;
    if (bracketCheck(str))
    {
        cout << "Output: Brackets are balanced." << endl;
    }
    else
    {
        cout << "Output: Brackets are not balanced." << endl;
    }

    str = "[(])";
    cout << "--------------------------------" << endl;
    cout << "Input is: " << str << endl;
    if (bracketCheck(str))
    {
        cout << "Output: Brackets are balanced." << endl;
    }
    else
    {
        cout << "Output: Brackets are not balanced." << endl;
    }

    str = "[()]{}{[()()]()}";
    cout << "--------------------------------" << endl;
    cout << "Input is: " << str << endl;
    if (bracketCheck(str))
    {
        cout << "Output: Brackets are balanced." << endl;
    }
    else
    {
        cout << "Output: Brackets are not balanced." << endl;
    }
    cout << "--------------------------------" << endl;

    return 0;
}
