#include <bits/stdc++.h>
using namespace std;

bool linearSearch(int arr[], int size, int key)
{
    if (size == 0)
        return 0;
    if (arr[0] == key)
        return 1;
    else
        return linearSearch(arr + 1, size - 1, key);
}

int main()
{
    int arr[] = {1, 2, 3, 8, 5, 6, 7, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << linearSearch(arr, size, 9);
    return 0;
}