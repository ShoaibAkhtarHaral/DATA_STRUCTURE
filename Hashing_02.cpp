#include <iostream>
using namespace std;

class reHashing
{
    int size, count;
    int *arr;

public:
    reHashing(int s)
    {
        size = s;
        count = 0;
        arr = new int[s];

        for (int i = 0; i < size; i++)
        {
            arr[i] = -1; // initialize all index with -1 to avoid garbage value
        }
    }

    ~reHashing()
    {
        delete[] arr;
    }

    void updateSize(int newSize)
    {
        size = newSize;
    }

    void resetCount()
    {
        count = 0;
    }

    int hashFunction(int val)
    {
        return val % size;
    }

    void New_Array()
    {
        int newSize = size * 2; // making the size double when the array is filled up 70%
        updateSize(newSize);
        int *arr2;
        arr2 = new int[size];
        resetCount(); // function for making count = 0 for new array

        for (int i = 0; i < size; i++)
        {
            arr2[i] = -1; // making the size double when the array is filled up 70%
        }

        for (int j = 0; j < size/2; j++)
        {
            if (arr[j] == -1)
            {
                continue;
            }

            else
            {
                int arrayValue = arr[j];
                int index = hashFunction(arrayValue);
                int i = 0;

                // Linear probing in the new array
                while (arr2[(index + i) % size] != -1 && arr2[(index + i) % size] != arrayValue)
                {
                    i++;
                }

                arr2[(index + i) % size] = arrayValue;
                count++;
            }
        }

        // Deallocate the memory for the old array
        delete[] arr;
        arr = arr2;
    }

    void insert(int val)
    {
        if (getPercentage() <= 70)
        {
            int index = hashFunction(val);
            int i = 0;

            while (arr[(index + i) % size] != -1 && arr[(index + i) % size] != val)
            {
                i++;
            }

            if (arr[(index + i) % size] == val)
            {
                cout << val << " Element already available, Duplicate not allowed" << endl;
            }
            else
            {
                arr[(index + i) % size] = val;
                count++;
                cout << val << " Element Insert SuccessFully" << endl;
            }
        }
        else
        {
            cout << "Array SIZE is more than 70%\nThen making a new Array and insert values in new array" << endl;
            New_Array();

            // now inserting a value in array that pass from main

            // use recursing for avoid reusing the code
            // insert(val);     //im using recursion for insertion but it is not good practice for large data

            // so i am using iterative method also here.
            int index = hashFunction(val);
            int i = 0;

            while (arr[(index + i) % size] != -1 && arr[(index + i) % size] != val)
            {
                i++;
            }

            if (arr[(index + i) % size] == val)
            {
                cout << val << " Element already available, Duplicate not allowed" << endl;
            }
            else
            {
                arr[(index + i) % size] = val;
                count++;
                cout << val << " Element Insert SuccessFully" << endl;
            }
        }
    }

    void display()
    {
        cout << "== Display ==" << endl;
        for (int i = 0; i < size; i++)
        {
            if (arr[i] == -1)
            {
                continue;
            }
            else
            {
                cout << " Index " << i << ": " << arr[i] << endl;
            }
        }
        cout << "=============" << endl;
        // cout << "total values: " << count << endl;
        // cout << "Total percentage: " << getPercentage() << endl;
    }

    int getPercentage()
    {
        float per = ((count * 100) / size);
        // cout << "Percentage is: " << per << endl;

        return per;
    }
};

int main()
{
    int n;
    cout << "Enter How many index you have: ";
    cin >> n;
    reHashing h(n);

    while (true)
    {
        int choice;
        cout << "\n------ MENU ------" << endl;
        cout << "| 1. Insertion   |" << endl;
        cout << "| 2. Display     |" << endl;
        cout << "| 3. EXIT        |" << endl;
        cout << "------------------" << endl;
        cout << " => ";
        cin >> choice;

        if (choice == 1)
        {
            int val;
            cout << "Enter value you want to insert: ";
            cin >> val;
            h.insert(val);
        }

        else if (choice == 2)
        {
            h.display();
        }

        else if (choice == 3)
        {
            break;
        }

        else
        {
            cout << "Invalid input" << endl;
        }
    }

    return 0;
}
