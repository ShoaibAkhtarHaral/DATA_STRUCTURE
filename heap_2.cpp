#include <iostream>
#include <vector>
using namespace std;
class heap
{
public:
    vector<int> htree;
    int getParent(int child)
    {
        int p = (child - 1) / 2;

        if (child == 0)
        {
            return -1;
        }
        else
        {
            return p;
        }
    }
    int getLeft(int parent)
    {
        int child = 2 * parent + 1;
        if (child < htree.size())
        {
            return child;
        }

        else
        {
            return -1;
        }
    }
    int getRight(int parent)
    {
        int child = 2 * parent + 2;
        if (child < htree.size())
        {
            return child;
        }
        else
        {
            return -1;
        }
    }
    void swap(int *a, int *b)
    {

        int temp = *a;
        *a = *b;
        *b = temp;
    }

    void heapifyUp(int node)
    {
        int parent = getParent(node);
        if (node >= 0 && parent >= 0 && htree[parent] > htree[node])
        {
            swap(&htree[node], &htree[parent]);
            heapifyUp(getParent(node));
        }
    }

    void heapifyDown(int node)
    {
        int lchild = getLeft(node);
        int rchild = getRight(node);
        int smallest;
        if (lchild >= 0 && rchild >= 0)
        {
            if (htree[lchild] < htree[rchild])
            {
                smallest = lchild;
            }
            else if (htree[rchild] < htree[lchild])
            {
                smallest = rchild;
            }
            if (smallest > 0)
            {
                swap(&htree[smallest], &htree[node]);
                heapifyDown(smallest);
            }
        }
    }

    void insert(int value)
    {
        int size = htree.size();
        if (size == 0)
        {
            htree.push_back(value);
        }
        else
        {
            htree.push_back(value);
            heapifyUp(htree.size() - 1);
        }
    }
    void del(int value)
    {
        int index = -1;
        for (int i = 0; i < htree.size(); i++)
        {
            if (htree[i] == value)
            {
                index = i;
                break;
            }
        }

        if (index != -1)
        {
            swap(&htree[index], &htree[htree.size() - 1]);
            htree.pop_back();
            heapifyDown(index);
        }
    }
    void display()
    {
        for (int i = 0; i < htree.size(); i++)
        {
            cout << htree[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    heap h;
    h.insert(5);
    h.insert(3);
    h.insert(8);
    h.insert(2);
    h.insert(7);
    h.display();
    h.del(5);
    h.del(3);
    h.display();
}