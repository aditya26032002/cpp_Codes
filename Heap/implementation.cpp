#include <bits/stdc++.h>
using namespace std;

class heap
{
    int *arr;
    int maxSize;
    int size;

public:
    heap(int size)
    {
        arr = new int[size + 1];
        this->maxSize = size;
        this->size = 0;
    }

    void insert(int val)
    {
        if (size == maxSize)
            return;
        size++;
        arr[size] = val;
        int i = size;
        while (i / 2 >= 1)
        {
            if (arr[i / 2] > arr[i])
                break;
            swap(arr[i / 2], arr[i]);
            i /= 2;
        }
    }

    void deleteNode()
    {
        if (size == 0)
            return;

        arr[1] = arr[size];
        size--;
        int i = 1;
        while (true)
        {
            int l = i * 2, r = i * 2 + 1;
            if (l <= size && arr[l] > arr[i])
            {
                swap(arr[i], arr[l]);
                i = l;
            }
            else if (r <= size && arr[r] > arr[i])
            {
                swap(arr[i], arr[r]);
                i = r;
            }
            else
                break;
        }
    }

    void print()
    {
        for (int i = 1; i <= size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

void heapify(int arr[], int size, int i)
{
    while (true)
    {
        int l = 2 * i, r = 2 * i + 1;
        int largest = i;

        if (l <= size && arr[l] < arr[i])
            largest = l;
        if (r <= size && arr[r] < arr[largest])
            largest = r;
        if (largest != i)
        {
            swap(arr[i], arr[largest]);
            i = largest;
        }
        else
            return;
    }
}

void buildHeap(int arr[], int size)
{
    for (int i = size / 2; i > 0; i--)
    {
        heapify(arr, size, i);
    }
}

void heapSort(int arr[], int size)
{
    buildHeap(arr, size);
    for (int n = size; n > 1;)
    {
        swap(arr[1], arr[n]);
        n--;
        heapify(arr, n, 1);
    }
}

int main()
{
    // heap h(6);
    // h.insert(60);
    // h.insert(50);
    // h.insert(10);
    // h.insert(30);
    // h.insert(20);
    // h.print();
    // h.insert(55);
    // h.print();
    // h.deleteNode();
    // h.print();

    int arr[6] = {-1, 54, 53, 55, 52, 50};
    buildHeap(arr, 5);
    for (int i = 1; i < 6; i++)
    {
        cout << arr[i] << " ";
    }
    heapSort(arr, 5);
    cout << endl
         << "Sorted: " << endl;
    for (int i = 1; i < 6; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}