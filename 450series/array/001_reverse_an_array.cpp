#include <bits/stdc++.h>
using namespace std;

void reverseArr(int arr[], int size)
{
    int i = 0, j = size - 1;
    while (i < j)
    {
        swap(arr[i], arr[j]);
        i++;
        j--;
    }
}

int main()
{
    int arr[] = {1, 2, 3};
    reverseArr(arr, 3);
    for (int i = 0; i < 3; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}