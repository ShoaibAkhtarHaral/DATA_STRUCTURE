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

    void push(int val)
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
            int val = arr[top];
            top--;
            return val;
        }
    }
};

int evaluatePostfixExpression(string s)
{
    stack operands(50);
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
        {
            continue;
        }

        if (s[i] == '+')
        {
            int operand2 = operands.pop();
            int operand1 = operands.pop();
            operands.push(operand1 + operand2);
        }
        else if (s[i] == '-')
        {
            int operand2 = operands.pop();
            int operand1 = operands.pop();
            operands.push(operand1 - operand2);
        }
        else if (s[i] == '*')
        {
            int operand2 = operands.pop();
            int operand1 = operands.pop();
            operands.push(operand1 * operand2);
        }
        else if (s[i] == '/')
        {
            int operand2 = operands.pop();
            int operand1 = operands.pop();
            operands.push(operand1 / operand2);
        }
        else
        {
            // Convert character to integer and push into the stack
            operands.push(s[i] - '0');
        }
    }
    return operands.pop();
}

int main()
{
    string str;
    int result;
    
    str = "2 3 1 * + 9 -";
    result = evaluatePostfixExpression(str);
    cout << "---------------------------";
    cout << "\nInput is: " << str << endl;
    cout << "Result is: " << result << endl;
    cout << "---------------------------" << endl;

    str = "5 3 + 8 2 - *";
    result = evaluatePostfixExpression(str);
    cout << "---------------------------";
    cout << "\nInput is: " << str << endl;
    cout << "Result is: " << result << endl;
    cout << "---------------------------" << endl;

    str = "4 5 6 * +";
    result = evaluatePostfixExpression(str);
    cout << "---------------------------";
    cout << "\nInput is: " << str << endl;
    cout << "Result is: " << result << endl;
    cout << "---------------------------" << endl;

    return 0;
}