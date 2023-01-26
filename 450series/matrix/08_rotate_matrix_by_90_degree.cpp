#include <bits/stdc++.h>
using namespace std;

void roatateMatrix(vector<vector<int>> &mat)
{
    int stRow = 0, stCol = 0;
    int enRow = mat.size() - 1, enCol = mat[0].size() - 1;
    while (stRow < enRow)
    {
        vector<int> temp;
        for (int r = stRow, c = stCol; r <= enRow && c <= enCol; r++, c++)
        {
            temp.push_back(mat[r][stCol]);
            mat[r][stCol] = mat[enRow][c];
        }
        for (int c = stCol, r = enRow; c <= enCol; c++, r--)
            mat[enRow][c] = mat[r][enCol];
        for (int r = enRow, c = enCol; r >= stRow; r--, c--)
            mat[r][enCol] = mat[stRow][c];
        for (int c = enCol, i = 0; c >= stCol; c--, i++)
            mat[stRow][c] = temp[i];
        stRow++;
        stCol++;
        enRow--;
        enCol--;
    }
}

int main()
{
    vector<vector<int>> mat = {{1, 2, 3, 4},
                               {5, 6, 7, 8},
                               {9, 10, 11, 12},
                               {13, 14, 15, 16}};
    roatateMatrix(mat);
    for (auto i : mat)
    {
        for (int j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}