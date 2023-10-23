#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to search a given number in row-column sorted matrix.
    bool search(vector<vector<int>> matrix, int n, int m, int x)
    {
        int row = 0, col = m - 1;
        while (row < n && col >= 0)
        {
            if (matrix[row][col] == x)
                return true;

            if (matrix[row][col] < x)
                row++;
            else
                col--;
        }
        return false;
    }
};

int main()
{

    return 0;
}