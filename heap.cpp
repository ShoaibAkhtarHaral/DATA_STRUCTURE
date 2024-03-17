#include <iostream>
using namespace std;

void heapify(int arr[], int size, int i)
{
    int smallest = i;
    int l = 2 * i;
    int r = 2 * i + 1;

    if (l <= size && arr[l] < arr[smallest])
    { 
        smallest = l;
    }

    if (r <= size && arr[r] < arr[smallest])
    {
        smallest = r;
    }

    if (smallest != i)
    {
        swap(arr[i], arr[smallest]);
        heapify(arr, size, smallest); // Recursively heapify the affected subtree
    }
}

void insertMin(int arr[], int &size, int val)
{
    size++;
    arr[size] = val;
    int i = size;

    while (i > 1)
    {
        int par = i / 2;
        if (arr[par] > arr[i])
        {
            swap(arr[par], arr[i]);
            i = par;
        }
        else
        {
            return;
        }
    }
}

void removeMin(int arr[], int &size)
{
    if (size < 1)
    {
        cout << "Heap is empty. Cannot delete." << endl;
        return;
    }

    swap(arr[1], arr[size]);
    size--;

    heapify(arr, size, 1); // Heapify the root element
}

void deleteElement(int arr[], int &size, int val)
{
    int i;
    for (i = 1; i <= size; i++)
    {
        if (arr[i] == val)
            break;
    }

    if (i > size)
    {
        cout << "Element not found in the heap." << endl;
        return;
    }

    swap(arr[i], arr[size]);
    size--;

    heapify(arr, size, i);
}

int main()
{
    int size = 0;
    int *arr = new int[size + 1]; // Start from index 1

    cout << "Minimum HEAP" << endl;

    while (1)
    {
        int ch;
        cout << "1. Insert" << endl;
        cout << "2. Delete Minimum" << endl;
        cout << "3. Delete Element" << endl;
        cout << "4. Display" << endl;
        cout << "5. Quit" << endl;
        cin >> ch;

        if (ch == 1)
        {
            int val;
            cout << "Enter value you want to insert: ";
            cin >> val;
            insertMin(arr, size, val);
        }
        else if (ch == 2)
        {
            removeMin(arr, size);
        }
        else if (ch == 3)
        {
            int val;
            cout << "Enter value you want to delete: ";
            cin >> val;
            deleteElement(arr, size, val);
        }
        else if (ch == 4)
        {
            for (int i = 1; i <= size; i++)
            {
                cout << arr[i] << " ";
            }
            cout << "\nTotal size is: " << size << endl;
            cout << endl;
        }
        else if (ch == 5)
        {
            break;
        }
    }

    delete[] arr;
    return 0;
}
