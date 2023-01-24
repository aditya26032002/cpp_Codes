#include <bits/stdc++.h>
using namespace std;

int rowWithMax1s(vector<vector<int>> arr, int n, int m)
{
    int ans = -1;
    int c = m - 1;
    for (int r = 0; r < n;)
    {
        if (arr[r][c] == 1)
        {
            ans = r;
            c--;
        }
        else
        {
            r++;
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> arr = {{0, 1, 1, 1}, {0, 0, 1, 1}, {1, 1, 1, 1}, {0, 0, 0, 0}};
    cout << rowWithMax1s(arr, 4, 4);
    return 0;
}