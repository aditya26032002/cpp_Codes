#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Complete this function
    // Function to check whether there is a subarray present with 0-sum or not.
    // Time : O(n)  Space : O(n)
    bool subArrayExists(int arr[], int n)
    {
        unordered_map<int, bool> mp;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            if (mp[sum] || sum == 0)
                return true;

            mp[sum] = true;
        }
        return false;
    }
};

int main()
{

    return 0;
}