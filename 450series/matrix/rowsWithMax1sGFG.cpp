#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Time : O(r*log(c))   Space : O(1)
    int count1s(vector<vector<int>> &arr, int &row, int &m)
    {
        int s = 0, e = m - 1;
        int firstOcc = -1;
        while (s <= e)
        {
            int mid = s + (e - s) / 2;
            if (arr[row][mid] == 1)
            {
                firstOcc = mid;
                e = mid - 1;
            }
            else
                s = mid + 1;
        }
        if (firstOcc == -1)
            return 0;
        return m - firstOcc;
    }

    int rowWithMax1s(vector<vector<int>> arr, int n, int m)
    {
        int ans = -1, maxCount = 0;
        for (int i = 0; i < n; i++)
        {
            int numOf1s = count1s(arr, i, m);

            if (numOf1s > maxCount)
            {
                ans = i;
                maxCount = numOf1s;
            }
        }
        return ans;
    }
};

int main()
{

    return 0;
}