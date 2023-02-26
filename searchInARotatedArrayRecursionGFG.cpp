#include <bits/stdc++.h>
using namespace std;

int findPivotIndex(int A[], int s, int e)
{
    int mid = s + (e - s) / 2;
    if (A[mid + 1] < A[mid] && A[mid + 1] < A[0])
        return mid + 1;
    if (A[mid] > A[0])
        return findPivotIndex(A, mid + 1, e);
    if (A[mid] < A[0])
        return findPivotIndex(A, s, mid - 1);
}

int binarySearch(int A[], int s, int e, int &key)
{
    int mid = s + (e - s) / 2;
    if (s > e)
        return -1;
    if (A[mid] == key)
        return mid;
    if (A[mid] > key)
        return binarySearch(A, s, mid - 1, key);
    else
        return binarySearch(A, mid + 1, e, key);
}

int search(int A[], int l, int h, int key)
{
    if (A[0] > A[h])
    {
        int pivIndex = findPivotIndex(A, 0, h);
        // cout << "Pivot index : " << pivIndex << endl;
        if (key >= A[0])
            return binarySearch(A, l, pivIndex - 1, key);
        else
            return binarySearch(A, pivIndex, h, key);
    }
    else
        return binarySearch(A, l, h, key);
}

int main()
{
    int A[] = {3, 5, 1, 2};
    int key = 6;
    cout << search(A, 0, 3, key);

    // int A[] = {5, 6, 7, 8, 9, 10, 1, 2, 3};
    // int key = 10;
    // cout << search(A, 0, 8, key);

    // int A[] = {3, 1};
    // int key = 1;
    // cout << search(A, 0, 1, key);

    // int A[] = {265, 670, 863, 950, 958};
    // int key = 892;
    // cout << search(A, 0, 3, key);
    return 0;
}