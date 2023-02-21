#include <bits/stdc++.h>
using namespace std;

int arrSum(int arr[], int size)
{
    if (size == 0)
        return 0;
    else
        return arr[0] + arrSum(arr + 1, size - 1);
}

int main()
{
    int arr[] = {1, 2, 3, 8, 5, 6, 7, 8};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << arrSum(arr, size);
    return 0;
}