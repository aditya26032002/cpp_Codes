#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int ans;
        for (int i = 0; i < nums.size(); i++)
        {
            int index = abs(nums[i]) - 1;
            if (nums[index] < 0)
            {
                ans = index + 1;
                break;
            }
            nums[index] = -nums[index];
        }
        for (int i = 0; i < nums.size(); i++)
            nums[i] = abs(nums[i]);
        return ans;
    }
};

int main()
{

    return 0;
}