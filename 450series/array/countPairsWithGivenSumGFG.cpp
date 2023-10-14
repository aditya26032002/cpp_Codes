#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Time : O(n)  Space : O(n)
    int getPairsCount(int arr[], int n, int k)
    {
        unordered_map<int, int> mp;
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (mp[k - arr[i]])
                count += mp[k - arr[i]];
            mp[arr[i]]++;
        }
        return count;
    }
};

int main()
{

    return 0;
}