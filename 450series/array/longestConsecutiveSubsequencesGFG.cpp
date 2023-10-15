#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // arr[] : the input array
    // N : size of the array arr[]

    // Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
        unordered_map<int, bool> mp;
        int mini = INT_MAX, maxi = INT_MIN;
        for (int i = 0; i < N; i++)
        {
            mini = min(mini, arr[i]);
            maxi = max(maxi, arr[i]);
            mp[arr[i]] = true;
        }

        int count = 1, ans = 1;

        while (mini <= maxi)
        {
            ans = max(ans, count);
            if (mp[mini] && mp[mini + 1])
            {
                count++;
            }
            else
            {
                count = 1;
            }
            mini++;
        }
        return ans;
    }
};

int main()
{

    return 0;
}