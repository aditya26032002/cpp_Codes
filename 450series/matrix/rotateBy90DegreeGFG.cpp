#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to rotate matrix anticlockwise by 90 degrees.
    void rotateby90(vector<vector<int>> &matrix, int n)
    {
        for (int r = 0, c = 0; r < n && c < n; r++, c++)
        {
            int i = r, j = c;
            while (i < n && j < n)
            {
                swap(matrix[i++][c], matrix[r][j++]);
            }
        }

        int strow = 0, enrow = n - 1;
        while (strow < enrow)
        {
            for (int c = 0; c < n; c++)
            {
                swap(matrix[strow][c], matrix[enrow][c]);
            }
            strow++;
            enrow--;
        }
    }
};

int main()
{

    return 0;
}