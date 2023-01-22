#include <bits/stdc++.h>
using namespace std;

// Not done
int median(vector<vector<int>> &matrix, int R, int C)
{
    sort(matrix.begin(), matrix.end());
    for (vector<int> i : matrix)
    {
        for (int j : i)
        {
            cout << j << " ";
        }
    }
}

int main()
{
    vector<vector<int>> matrix = {{1, 3, 5}, {2, 6, 9}, {3, 6, 9}};
    median(matrix, 3, 3);
    return 0;
}