#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void traverse(vector<vector<int>> &m, int &n, int i, int j, string path, vector<string> &paths)
    {
        if (m[i][j] == 0)
            return;

        if (i == n - 1 && j == n - 1)
        {
            paths.push_back(path);
            return;
        }

        m[i][j] = 0;
        // down
        if (i + 1 < n)
            traverse(m, n, i + 1, j, path + 'D', paths);
        // left
        if (j - 1 >= 0)
            traverse(m, n, i, j - 1, path + 'L', paths);
        // right
        if (j + 1 < n)
            traverse(m, n, i, j + 1, path + 'R', paths);
        // up
        if (i - 1 >= 0)
            traverse(m, n, i - 1, j, path + 'U', paths);
        m[i][j] = 1;
    }

    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        vector<string> paths;
        traverse(m, n, 0, 0, "", paths);
        return paths;
    }
};

int main()
{

    return 0;
}