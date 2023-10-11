#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to merge the arrays.
    //  Time : O(min(n,m) + nlogn + mlogm)  Space: O(1)
    void merge(long long arr1[], long long arr2[], int n, int m)
    {
        int pt1 = n - 1, pt2 = 0;
        while (pt1 >= 0 && pt2 < m)
        {
            if (arr1[pt1] < arr2[pt2])
                break;
            swap(arr1[pt1--], arr2[pt2++]);
        }
        sort(arr1, arr1 + n);
        sort(arr2, arr2 + m);
    }
    /*
    // Time : O(n + m)  Space : O(n + m)
    void merge(long long arr1[], long long arr2[], int n, int m)
    {
        priority_queue<long long, vector<long long>, greater<long long>> minHeap;
        for (int i = 0; i < n; i++)
        {
            minHeap.push(arr1[i]);
        }
        for (int i = 0; i < m; i++)
        {
            minHeap.push(arr2[i]);
        }
        for (int i = 0; i < n; i++)
        {
            arr1[i] = minHeap.top();
            minHeap.pop();
        }
        for (int i = 0; i < m; i++)
        {
            arr2[i] = minHeap.top();
            minHeap.pop();
        }
    }
    */
};

int main()
{

    return 0;
}