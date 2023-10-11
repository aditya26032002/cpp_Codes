#include <bits/stdc++.h>
using namespace std;

#define N 9

class Solution
{
public:
    // Function to find a solved Sudoku.

    int findBlockNum(int row, int col)
    {
        if (col < 3)
        {
            if (row < 3)
                return 1;
            if (row < 6)
                return 2;
            if (row < 9)
                return 3;
        }
        if (col < 6)
        {
            if (row < 3)
                return 4;
            if (row < 6)
                return 5;
            if (row < 9)
                return 6;
        }
        if (col < 9)
        {
            if (row < 3)
                return 7;
            if (row < 6)
                return 8;
            if (row < 9)
                return 9;
        }
    }

    bool isSafeToPut(int val, int row, int col, map<pair<int, int>, bool> &rowMp, map<pair<int, int>, bool> &colMp, map<pair<int, int>, bool> &blockMp)
    {
        if (rowMp[{row, val}])
            return false;
        if (colMp[{col, val}])
            return false;
        int block = findBlockNum(row, col);
        if (blockMp[{block, val}])
            return false;

        return true;
    }

    bool putValues(int grid[N][N], int row, int col, map<pair<int, int>, bool> &rowMp, map<pair<int, int>, bool> &colMp, map<pair<int, int>, bool> &blockMp)
    {
        if (row >= N || col >= N)
            return true;

        if (grid[row][col] == 0)
        {
            for (int val = 1; val <= 9; val++)
            {
                if (isSafeToPut(val, row, col, rowMp, colMp, blockMp))
                {
                    rowMp[{row, val}] = true;
                    colMp[{col, val}] = true;
                    int block = findBlockNum(row, col);
                    blockMp[{block, val}] = true;
                    grid[row][col] = val;

                    bool valid = false;
                    if (col + 1 < N)
                    {
                        valid = putValues(grid, row, col + 1, rowMp, colMp, blockMp);
                    }
                    else
                        valid = putValues(grid, row + 1, 0, rowMp, colMp, blockMp);

                    if (valid)
                        return true;

                    rowMp[{row, val}] = false;
                    colMp[{col, val}] = false;
                    blockMp[{block, val}] = false;
                    grid[row][col] = 0;
                }
            }
        }
        else
        {
            bool valid = false;
            if (col + 1 < N)
            {
                valid = putValues(grid, row, col + 1, rowMp, colMp, blockMp);
            }
            else
                valid = putValues(grid, row + 1, 0, rowMp, colMp, blockMp);

            if (valid)
                return true;
        }
        return false;
    }

    bool SolveSudoku(int grid[N][N])
    {
        // {row/col/blockNum, value} = true/false
        map<pair<int, int>, bool> rowMp, colMp, blockMp;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (grid[i][j] == 0)
                    continue;
                if (rowMp.find({i, grid[i][j]}) != rowMp.end())
                    return false;
                rowMp[{i, grid[i][j]}] = true;

                if (colMp.find({j, grid[i][j]}) != colMp.end())
                    return false;
                colMp[{j, grid[i][j]}] = true;

                int blockNum = findBlockNum(i, j);
                if (blockMp.find({blockNum, grid[i][j]}) != blockMp.end())
                    return false;
                blockMp[{blockNum, grid[i][j]}] = true;
            }
        }

        return putValues(grid, 0, 0, rowMp, colMp, blockMp);
    }

    // Function to print grids of the Sudoku.
    void printGrid(int grid[N][N])
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
                cout << grid[i][j] << " ";
        }
    }
};

int main()
{

    return 0;
}