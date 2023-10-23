#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countLowerValues(vector<vector<int>> &matrix, int &row, int &C, int &val)
    {
        int s = 0, e = C - 1;
        int ans = -1;
        while (s <= e)
        {
            int mid = s + (e - s) / 2;
            if (matrix[row][mid] <= val)
            {
                ans = mid;
                s = mid + 1;
            }
            else
                e = mid - 1;
        }
        if (ans == -1)
            return 0;
        return ans + 1;
    }

    bool isPossible(vector<vector<int>> &matrix, int &R, int &C, int &mid)
    {
        int reqMinCount = (R * C + 1) / 2, count = 0;
        for (int i = 0; i < R; i++)
        {
            count += countLowerValues(matrix, i, C, mid);
            if (count >= reqMinCount)
                return true;
        }
        return false;
    }

    int median(vector<vector<int>> &matrix, int R, int C)
    {
        int s = INT_MAX, e = INT_MIN;
        for (int i = 0; i < R; i++)
        {
            s = min(s, matrix[i][0]);
            e = max(e, matrix[i][C - 1]);
        }

        int ans = -1;
        while (s <= e)
        {
            int mid = s + (e - s) / 2;
            if (isPossible(matrix, R, C, mid))
            {
                ans = mid;
                e = mid - 1;
            }
            else
                s = mid + 1;
        }
        return ans;
    }
};

int main()
{

    return 0;
}