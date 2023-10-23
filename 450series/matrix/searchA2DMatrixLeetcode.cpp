#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int rowCount = matrix.size(), colCount = matrix[0].size();
        int s = 0, e = rowCount * colCount - 1;
        while (s <= e)
        {
            int mid = s + (e - s) / 2;
            int row = mid / colCount;
            int col = mid % colCount;

            if (matrix[row][col] == target)
                return true;
            else if (matrix[row][col] < target)
                s = mid + 1;
            else
                e = mid - 1;
        }
        return false;
    }
};

int main()
{

    return 0;
}