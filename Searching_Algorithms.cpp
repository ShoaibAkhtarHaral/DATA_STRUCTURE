#include<iostream>

using namespace std;

int linearSearch(int arr[], int size, int val)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == val)
            return i;        
    }
    return -1; //not found   
}

int binarySearch(int arr[], int l, int r, int val)
{
    if (l <= r)
    {
        int mid = (l + r)/2;

        if(arr[mid] == val)
            return mid;

        if(arr[mid] < val)
            return binarySearch(arr, mid + 1, r, val);
        else
            return binarySearch(arr, l, mid - 1, val);
    }
    return -1;    
}

void printArr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout<<arr[i]<<"\t";

    cout<<endl;
}
int main()
{
    cout<<"Linear Search: ";
    cout<<linearSearch(arr5, 5, 5)<<endl;

    cout<<"Binary Search: ";
    cout<<binarySearch(arr5, 0, 4, 4)<<endl;
    return 0;
}
