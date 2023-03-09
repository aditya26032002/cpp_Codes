#include <bits/stdc++.h>
using namespace std;

void createSubset(vector<int> &nums, vector<int> sub, vector<vector<int>> &ans, int i)
{
    if (i == nums.size())
    {
        ans.push_back(sub);
        return;
    }
    // Exclude nums[i] in sub
    createSubset(nums, sub, ans, i + 1);
    // Include nums[i] in sub
    sub.push_back(nums[i]);
    createSubset(nums, sub, ans, i + 1);
}

vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> sub = {};
    int i = 0;
    createSubset(nums, sub, ans, i);
    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans = subsets(nums);
    for (auto i : ans)
    {
        cout << "{";
        for (int j : i)
        {
            cout << j << " ";
        }
        cout << "}" << endl;
    }
    return 0;
}