#include <bits/stdc++.h>
using namespace std;

vector<int> findCommonElements(vector<vector<int>> &mat)
{
    int rows = mat.size();
    int cols = mat[0].size();
    vector<int> ans;
    unordered_map<int, bool> mp;
    for (int i = 0; i < cols; i++)
    {
        mp[mat[0][i]] = true;
        if (rows == 1)
            ans.push_back(mat[0][i]);
    }
    if (rows == 1)
        return ans;

    for (int i = 1; i < rows; i++)
    {
        unordered_map<int, bool> temp;

        for (auto element : mat[i])
        {
            temp[element] = true;
        }
        unordered_map<int, bool> similars;
        for (auto i : temp)
        {
            if (temp[i.first] && mp[i.first])
                similars[i.first] = true;
        }
        mp = similars;
    }
    for (auto i : mp)
        ans.push_back(i.first);
    return ans;
}

int main()
{

    return 0;
}