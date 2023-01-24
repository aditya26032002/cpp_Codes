#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<vector<int>> &matrix, int R, int C, int mid)
{
    int count = 0;
    int half = (R * C + 1) / 2;
    for (int r = 0; r < R; r++)
    {
        for (int c = 0; c < C; c++)
        {
            if (matrix[r][c] <= mid)
                count++;
            if (count == half)
                return 1;
            if (matrix[r][c] >= mid)
                break;
        }
    }
    return 0;
}

int median(vector<vector<int>> &matrix, int R, int C)
{
    int max = matrix[R - 1][C - 1];
    int min = matrix[0][0];
    int s = min, e = max;
    int mid = s + (e - s) / 2;
    int ans;
    while (s <= e)
    {
        if (isPossible(matrix, R, C, mid))
        {
            ans = mid;
            e = mid - 1;
        }
        else
            s = mid + 1;
        mid = s + (e - s) / 2;
    }
    return ans;
}

int main()
{
    vector<vector<int>> matrix = {{1, 3, 5}, {2, 6, 9}, {3, 6, 9}};
    cout << median(matrix, 3, 3);
    return 0;
}