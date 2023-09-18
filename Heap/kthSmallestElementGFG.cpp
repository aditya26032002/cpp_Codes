#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function

    void heapify(int arr[], int n, int i)
    {
        while (true)
        {
            int l = 2 * i + 1, r = i * 2 + 2;
            int smallest = i;
            if (l < n && arr[l] < arr[smallest])
                smallest = l;
            if (r < n && arr[r] < arr[smallest])
                smallest = r;

            if (smallest != i)
            {
                swap(arr[i], arr[smallest]);
                i = smallest;
            }
            else
                return;
        }
    }

    void buildHeap(int arr[], int n)
    {
        for (int i = (n / 2) - 1; i >= 0; i--)
            heapify(arr, n, i);
    }

    int kthSmallest(int arr[], int l, int r, int k)
    {
        int size = r - l + 1;
        buildHeap(arr, size);
        int ans = arr[0];

        while (k--)
        {
            ans = arr[0];
            swap(arr[0], arr[size - 1]);
            size--;
            heapify(arr, size, 0);
        }
        return ans;
    }
};

int main()
{

    return 0;
}