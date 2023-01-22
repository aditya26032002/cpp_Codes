#include <bits/stdc++.h>
using namespace std;

void moveNegatives(int arr[], int size)
{
    int s = 0, e = size - 1;
    while (s < e)
    {
        if (arr[s] >= 0 && arr[e] < 0)
        {
            swap(arr[s], arr[e]);
            s++;
            e--;
        }
        else if (arr[s] < 0)
        {
            s++;
        }
        else
        {
            e--;
        }
    }
}

int main()
{
    int arr[] = {-12, 11, -13, -5, 6, -7, 5, -3, -6};
    moveNegatives(arr, 9);
    for (int i = 0; i < 9; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}