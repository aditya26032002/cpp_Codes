#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void storeAns(int &n, vector<vector<int>> &board, vector<vector<int>> &ans)
    {
        vector<int> temp;
        for (int j = 0; j < n; j++)
        {
            for (int i = 0; i < n; i++)
            {
                if (board[i][j] == 1)
                    temp.push_back(i + 1);
            }
        }
        ans.push_back(temp);
    }

    void markUnsafePos(int &n, vector<vector<int>> &board, int x, int y)
    {
        // row
        for (int j = y + 1; j < n; j++)
        {
            board[x][j]--;
        }
        // diagonal
        int i = x + 1, j = y + 1;
        while (i < n && j < n)
        {
            board[i++][j++]--;
        }
        i = x - 1;
        j = y + 1;
        while (i >= 0 && j < n)
        {
            board[i--][j++]--;
        }
    }

    void unmarkPos(int &n, vector<vector<int>> &board, int x, int y)
    {
        // row
        for (int j = y + 1; j < n; j++)
        {
            board[x][j]++;
        }
        // diagonal
        int i = x + 1, j = y + 1;
        while (i < n && j < n)
        {
            board[i++][j++]++;
        }
        i = x - 1;
        j = y + 1;
        while (i >= 0 && j < n)
        {
            board[i--][j++]++;
        }
    }

    void placeQueens(int queens, int &n, vector<vector<int>> &board, vector<vector<int>> &ans, int y)
    {
        if (y >= n)
            return;

        for (int x = 0; x < n; x++)
        {
            if (board[x][y] == 0)
            {
                board[x][y] = 1;
                queens--;
                if (queens == 0)
                {
                    storeAns(n, board, ans);
                }
                else
                {
                    markUnsafePos(n, board, x, y);
                    placeQueens(queens, n, board, ans, y + 1);
                    unmarkPos(n, board, x, y);
                }
                board[x][y] = 0;
                queens++;
            }
        }
    }

    vector<vector<int>> nQueen(int n)
    {
        vector<int> temp(n, 0);
        vector<vector<int>> board;
        for (int i = 0; i < n; i++)
        {
            board.push_back(temp);
        }
        vector<vector<int>> ans;
        placeQueens(n, n, board, ans, 0);
        return ans;
    }
};

int main()
{

    return 0;
}