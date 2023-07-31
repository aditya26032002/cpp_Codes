#include <bits/stdc++.h>
using namespace std;

// not done
vector<int> sumOfMinAndMax(int *arr, int n, int k)
{
    int min = INT_MAX, max = INT_MIN;
    queue<int> window;
    for (int i = 0; i < k; i++)
    {
        window.push(arr[i]);
        if (arr[i] < min)
            min = arr[i];
        if (arr[i] > max)
            max = arr[i];
    }
}

int main()
{
    int arr[] = {2, 5, -1, 7, -3, -1, -2};
    int k = 4;
    int n = sizeof(arr) / sizeof(int);
    vector<int> ans = sumOfMinAndMax(arr, n, k);
    return 0;
}