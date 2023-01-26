#include <bits/stdc++.h>
using namespace std;

// Not working

int area(vector<vector<int>> &M, int n, int m, int upLeft, int upRight, int r)
{
    int row = r + 1;
    while (row < n && (M[row][upLeft] == 1 && M[row][upRight] == 1))
    {
        int c = upLeft;
        while (c < upRight && M[row][c] == 1)
        {
            c++;
        }
        if (c != upRight)
            break;
        row++;
    }
    return (upRight - upLeft + 1) * (row - r);
}

int maxArea(vector<vector<int>> &M, int n, int m)
{
    int maxAr = 0;
    int r = 0;
    int upLeft, upRight;
    while (r < n)
    {
        int c = 0;
        upLeft = upRight = 0;
        while (c < m)
        {
            while (c < m && M[r][c] != 1)
            {
                c++;
            }
            if (c == m)
                break;
            upLeft = upRight = c;
            while (c < m && M[r][c] != 0)
            {
                c++;
            }
            upRight = c - 1;
            int tempArea = area(M, n, m, upLeft, upRight, r);
            cout << tempArea << endl;
            if (tempArea > maxAr)
            {
                maxAr = tempArea;
            }
        }
        r++;
    }
    return maxAr;
}

int main()
{
    vector<vector<int>> M = {{1, 0, 1, 0}, {1, 1, 1, 1}, {1, 1, 0, 1}, {1, 1, 0, 1}, {0, 0, 0, 1}, {0, 1, 0, 0}};
    cout << maxArea(M, 6, 4);
    return 0;
}