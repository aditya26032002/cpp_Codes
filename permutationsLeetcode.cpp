#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &sub, int index, vector<vector<int>> &ans)
{
    if (index == sub.size())
    {
        ans.push_back(sub);
        return;
    }
    for (int j = index; j < sub.size(); j++)
    {
        swap(sub[index], sub[j]);
        solve(sub, index + 1, ans);
        swap(sub[index], sub[j]);
    }
}

vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> ans;
    solve(nums, 0, ans);
    return ans;
}

int main()
{
    vector<int> input = {1, 2, 3};
    vector<vector<int>> ans = permute(input);
    for (auto i : ans)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}