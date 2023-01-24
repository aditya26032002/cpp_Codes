#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> sortedMatrix(int N, vector<vector<int>> Mat)
{
    vector<int> temp;
    vector<vector<int>> ans;
    for (auto i : Mat)
    {
        for (int j : i)
        {
            temp.push_back(j);
        }
    }
    sort(temp.begin(), temp.end());
    int i = 0;
    vector<int> temp2;
    while (i < temp.size())
    {
        temp2.push_back(temp[i]);
        i++;
        if (i % N == 0)
        {
            ans.push_back(temp2);
            temp2.clear();
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> mat = {{10, 20, 30, 40}, {15, 25, 35, 45}, {27, 29, 37, 48}, {32, 33, 39, 50}};
    vector<vector<int>> ans = sortedMatrix(4, mat);
    for (auto i : ans)
    {
        for (int j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}