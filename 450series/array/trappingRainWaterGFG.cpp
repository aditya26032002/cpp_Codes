#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // Function to find the trapped water between the blocks.
public:
    long long trappingWater(int arr[], int n)
    {
        int pre[n], suff[n], preMax = INT_MIN, suffMax = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            preMax = max(preMax, arr[i]);
            pre[i] = preMax;

            suffMax = max(suffMax, arr[n - i - 1]);
            suff[n - i - 1] = suffMax;
        }

        long long ans = 0;
        for (int i = 1; i < n - 1; i++)
        {
            long long currStorage = min(pre[i], suff[i]) - arr[i];
            if (currStorage > 0)
                ans += currStorage;
        }
        return ans;
    }
};

int main()
{

    return 0;
}