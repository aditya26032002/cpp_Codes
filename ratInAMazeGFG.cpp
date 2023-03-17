#include <bits/stdc++.h>
using namespace std;

void takeStep(vector<vector<int>> &m, int n, int i, int j, string path, vector<string> &ans)
{
    if (i == n - 1 && j == n - 1)
    {
        ans.push_back(path);
        return;
    }
    m[i][j] = 0;
    // Down
    if (i + 1 < n && m[i + 1][j] != 0)
    {
        path.push_back('D');
        takeStep(m, n, i + 1, j, path, ans);
        path.pop_back();
    }
    // Left
    if (j - 1 >= 0 && m[i][j - 1] != 0)
    {
        path.push_back('L');
        takeStep(m, n, i, j - 1, path, ans);
        path.pop_back();
    }
    // Right
    if (j + 1 < n && m[i][j + 1] != 0)
    {
        path.push_back('R');
        takeStep(m, n, i, j + 1, path, ans);
        path.pop_back();
    }
    // Up
    if (i - 1 >= 0 && m[i - 1][j] != 0)
    {
        path.push_back('U');
        takeStep(m, n, i - 1, j, path, ans);
        path.pop_back();
    }
    m[i][j] = 1;
}

vector<string> findPath(vector<vector<int>> &m, int n)
{
    vector<string> ans;
    if (m[0][0] != 0)
        takeStep(m, n, 0, 0, "", ans);
    if (ans.size() == 0)
    {
        string temp = "-1";
        ans.push_back(temp);
    }
    return ans;
}

int main()
{
    // vector<vector<int>> m = {{1, 0, 0, 0},
    //                          {1, 1, 0, 0},
    //                          {1, 1, 0, 0},
    //                          {0, 1, 1, 1}};
    // vector<vector<int>> m = {{1, 0},
    //                          {1, 0}};
    vector<vector<int>> m = {{0, 1, 1, 1},
                             {1, 1, 1, 0},
                             {1, 0, 1, 1},
                             {0, 0, 1, 1}};

    vector<string> ans = findPath(m, m.size());
    for (auto i : ans)
        cout << i << endl;
    return 0;
}