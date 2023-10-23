#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int>> matrix, int r, int c)
    {
        vector<int> traverse;
        int totEl = r * c;
        int stRow = 0, stCol = 0;
        int enRow = r - 1, enCol = c - 1;
        while (totEl > 0)
        {
            // starting row
            for (int j = stCol; j <= enCol && totEl > 0; j++, totEl--)
                traverse.push_back(matrix[stRow][j]);

            stRow++;
            // col downward
            for (int i = stRow; i <= enRow && totEl > 0; i++, totEl--)
                traverse.push_back(matrix[i][enCol]);

            enCol--;
            // ending row
            for (int j = enCol; j >= stCol && totEl > 0; j--, totEl--)
                traverse.push_back(matrix[enRow][j]);

            enRow--;
            // starting col upward
            for (int i = enRow; i >= stRow && totEl > 0; i--, totEl--)
                traverse.push_back(matrix[i][stCol]);

            stCol++;
        }
        return traverse;
    }
};

int main()
{

    return 0;
}