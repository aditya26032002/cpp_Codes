#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TLE  Time : O(2^n)  Space : O(n)
    void solve(vector<int> &nums, int numsPtr, int &k, vector<int> &lines, int linePtr, int currCost, int &minCost)
    {
        if (numsPtr >= nums.size() - 1)
        {
            // for(auto i:lines)
            //     cout<<i<<" ";
            // cout<<"->"<<currCost<<endl;
            minCost = min(minCost, currCost);
            return;
        }

        int sum = 0;
        int count = 0;
        while (numsPtr < nums.size())
        {
            sum += nums[numsPtr++];
            count++;
            if (sum + count - 1 > k)
                break;
            lines[linePtr] = sum;
            int cost = (k - sum - (count - 1));
            cost *= cost;
            if (numsPtr == nums.size())
            {
                minCost = min(minCost, currCost);
                return;
            }
            solve(nums, numsPtr, k, lines, linePtr + 1, currCost + cost, minCost);
        }
    }

    int solveWordWrap(vector<int> nums, int k)
    {
        vector<int> lines(nums.size());
        int minCost = INT_MAX;
        solve(nums, 0, k, lines, 0, 0, minCost);
        return minCost;
    }
};

int main()
{

    return 0;
}