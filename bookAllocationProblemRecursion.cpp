#include <bits/stdc++.h>
using namespace std;

bool isPossible(int A[], int N, int M, int pages)
{
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        if (sum + A[i] <= pages)
            sum += A[i];
        else
        {
            M--;
            sum = A[i];
            if (M == 0)
                return false;
        }
    }
    return true;
}

int binarySearch(int A[], int N, int M, int s, int e, int ans)
{
    if (s > e)
        return ans;
    int mid = s + (e - s) / 2;
    if (isPossible(A, N, M, mid))
    {
        ans = mid;
        return binarySearch(A, N, M, s, mid - 1, ans);
    }
    else
        return binarySearch(A, N, M, mid + 1, e, ans);
}

int findPages(int A[], int N, int M)
{
    if (N < M)
        return -1;
    int s = INT_MIN, e = 0;
    for (int i = 0; i < N; i++)
    {
        s = max(s, A[i]);
        e += A[i];
    }

    return binarySearch(A, N, M, s, e, -1);
}

int main()
{
    // int A[] = {13, 31, 37, 45, 46, 54, 55, 63, 73, 84, 85};
    int A[] = {15, 10, 19, 10, 5, 18, 7};
    // int A[] = {12, 34, 67, 90};
    cout << findPages(A, 7, 5);
    return 0;
}