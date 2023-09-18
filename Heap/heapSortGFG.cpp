#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Heapify function to maintain heap property.
    void heapify(int arr[], int n, int i)
    {
        while (true)
        {
            int l = 2 * i + 1, r = 2 * i + 2;
            int largest = i;

            if (l < n && arr[l] > arr[largest])
                largest = l;
            if (r < n && arr[r] > arr[largest])
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

public:
    // Function to build a Heap from array.
    void buildHeap(int arr[], int n)
    {
        for (int i = (n / 2) - 1; i >= 0; i--)
        {
            heapify(arr, n, i);
        }
    }

public:
    // Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n)
    {
        buildHeap(arr, n);
        for (int size = n; size > 0;)
        {
            swap(arr[0], arr[size - 1]);
            size--;
            heapify(arr, size, 0);
        }
    }
};

int main()
{

    return 0;
}