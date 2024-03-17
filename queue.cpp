#include <iostream>
using namespace std;

class Queues
{
    int *arr;
    int length, capacity;
    int front, rear;

public:
    Queues(int s)
    {
        arr = new int[s];
        capacity = s;
        length = 0;
        front = 0;
        rear = -1;
    }

    ~Queues()
    {
        delete[] arr;
    }

    bool isEmpty()
    {
        if (length == 0)
            return true;
        else
            return false;
    }

    bool isFull()
    {
        if (length == capacity)
            return true;

        else
            return false;
    }

    void EnQueue(int val)
    {
        if (!isFull())
        {
            if (rear == (capacity - 1))
            {
                rear = 0;
            }

            else
            {
                rear++;
            }

            arr[rear] = val;
            length++;
        }
        else
        {
            cout << "OverFloww" << endl;
        }
    }

    int DeQueue()
    {
        if (!isEmpty())
        {
            int val = arr[front];
            if (front == (capacity - 1))
            {
                front = 0;
            }
            else
                front++;

            length--;
            return val;
        }
        else
        {
            cout << "UnderFlow" << endl;
            return -1;
        }
    }

    void display()
    {
        int index = front;
        for (int i = 0; i < length; i++)
        {
            cout << arr[index] << " ";
            if (index == (capacity - 1))
            {
                index = 0;
            }
            else
            {
                index++;
            }
        }
        cout << endl;
    }
};
int main()
{
    Queues q(5);
    q.EnQueue(5);
    q.EnQueue(2);
    q.EnQueue(6);
    q.EnQueue(1);
    q.display();
    q.DeQueue();
    q.display();
    q.EnQueue(10);
    q.display();
    q.EnQueue(111);
    q.display();
    q.DeQueue();
    
    return 0;
}