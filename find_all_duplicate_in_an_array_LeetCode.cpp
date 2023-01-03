#include <bits/stdc++.h>
using namespace std;

// Unable to do in O(n)
vector<int> findDuplicates(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    vector<int> twice;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == nums[i + 1])
        {
            twice.push_back(nums[i]);
            i++;
        }
    }
    return twice;
}

int main()
{
    vector<int> arr = {4,3,2,7,8,2,3,1};
    vector<int> twice = findDuplicates(arr);
    for(int i : twice){
        cout<<i<<" ";
    }
    return 0;
}