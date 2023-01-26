#include <bits/stdc++.h>
using namespace std;

int kthSmallest(vector<vector<int>> &mat, int k)
{
    vector<int> temp;
    for (auto i : mat)
    {
        for (int j : i)
        {
            temp.push_back(j);
        }
    }
    sort(temp.begin(), temp.end());
    return temp[k - 1];
}

int main()
{
    vector<vector<int>> mat = {{16, 28, 60, 64},
                               {22, 41, 63, 91},
                               {27, 50, 87, 93},
                               {36, 78, 87, 94}};
    cout << kthSmallest(mat, 3);
    return 0;
}