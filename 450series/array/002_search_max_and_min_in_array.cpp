#include <bits/stdc++.h>
using namespace std;

// Max Min
int findSum(int A[], int N)
{
    int maxi = INT_MIN, mini = INT_MAX;
    for (int i = 0, j = N - 1; i <= j; i++, j--)
    {
        if (A[i] > maxi)
            maxi = A[i];
        if (A[i] < mini)
            mini = A[i];
        if (A[j] > maxi)
            maxi = A[j];
        if (A[j] < mini)
            mini = A[j];
    }
    cout << maxi << " " << mini << endl;
    return maxi + mini;
}

int main()
{
    int arr[] = {-2, 1, -4, 5, 3};
    cout << findSum(arr, 5);
    return 0;
}