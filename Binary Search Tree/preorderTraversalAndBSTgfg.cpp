#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void canBuild(int arr[], int &N, int &i, int mini, int maxi)
    {
        if (i == N)
            return;

        if (arr[i] > mini && arr[i] < maxi)
        {
            int curr = arr[i];
            i++;
            canBuild(arr, N, i, mini, curr);
            canBuild(arr, N, i, curr, maxi);
        }
    }

    bool sorted(int arr[], int N, bool increasingOrder)
    {
        if (increasingOrder)
        {
            int prev = arr[0];
            for (int i = 1; i < N; i++)
            {
                if (arr[i] <= prev)
                    return false;
                prev = arr[i];
            }
            return true;
        }
        else
        {
            int prev = arr[0];
            for (int i = 1; i < N; i++)
            {
                if (arr[i] >= prev)
                    return false;
                prev = arr[i];
            }
            return true;
        }
    }

    int canRepresentBST(int arr[], int N)
    {
        if (sorted(arr, N, true) || sorted(arr, N, false))
            return 1;

        int i = 0;
        canBuild(arr, N, i, INT_MIN, INT_MAX);
        if (i >= N)
            return 1;
        return 0;
    }
};

int main()
{

    return 0;
}