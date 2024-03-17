#include <iostream>
using namespace std;

class HashTable
{
private:
    int SIZE;
    int *arr;

public:
    HashTable(int s)
    {
        SIZE = s;
        arr = new int[s];
        for (int i = 0; i < s; i++)
        {
            arr[i] = -1;
        }
    }

    int hashFunction(int key)
    {
        return key % SIZE;
    }

    void insert(int key)
    {
        int index = hashFunction(key);
        int i = 0;

        while (arr[(index + i) % SIZE] != -1 && arr[(index + i) % SIZE] != -2 && arr[(index + i) % SIZE] != key)
        {
            i++;
        }

        if (arr[(index + i) % SIZE] == key)
        {
            cout << "Element already exists in the hash table" << endl;
        }
        else
        {
            arr[(index + i) % SIZE] = key;
        }
    }

    void remove(int key)
    {
        int index = hashFunction(key);
        int i = 0;

        while (arr[(index + i) % SIZE] != -1)
        {
            if (arr[(index + i) % SIZE] == key)
            {
                arr[(index + i) % SIZE] = -2;
                cout << "Element deleted from the hash table" << endl;
                return;
            }
            i++;
        }

        cout << "Element not found in the hash table" << endl;
    }

    void display()
    {
        for (int i = 0; i < SIZE; i++)
        {
            if (arr[i] == -1)
            {
                continue;
            }
            cout << "Index " << i << ": " << arr[i] << endl;
        }
    }
};

int main()
{
    HashTable ht(5);
    ht.insert(5);
    ht.insert(15);
    ht.insert(25);
    ht.insert(35);
    ht.insert(45);
    ht.display();

    return 0;
}