#include <bits/stdc++.h>
using namespace std;

void sort012(int A[], int n)
{
    int _0s = 0, _1s = 0;
    for (int i = 0; i < n; i++)
    {
        if (A[i] == 0)
            _0s++;
        else if (A[i] == 1)
            _1s++;
    }
    for (int i = 0; i < n; i++)
    {
        if (_0s)
        {
            A[i] = 0;
            _0s--;
        }
        else if (_1s)
        {
            A[i] = 1;
            _1s--;
        }
        else
        {
            A[i] = 2;
        }
    }
}

int main()
{
    int arr[] = {0, 2, 1, 2, 0};
    sort012(arr, 5);
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}