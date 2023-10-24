#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> getMaxMatrix(vector<vector<int>> &mat, int &n)
{
    vector<int> temp(n);
    vector<vector<int>> maxMat;
    for (int i = 0; i < n; i++)
        maxMat.push_back(temp);

    for (int i = n - 1; i > 0; i--)
    {
        for (int j = n - 1; j > 0; j--)
        {
            maxMat[i][j] = mat[i][j];
            if (j + 1 < n)
                maxMat[i][j] = max(maxMat[i][j], maxMat[i][j + 1]);
            if (i + 1 < n)
                maxMat[i][j] = max(maxMat[i][j], maxMat[i + 1][j]);
        }
    }
    return maxMat;
}
int findMaxValue(vector<vector<int>> &mat, int n)
{
    vector<vector<int>> maxMat = getMaxMatrix(mat, n);

    int maxDiff = INT_MIN;
    for (int c = 0; c < n - 1; c++)
    {
        for (int d = 0; d < n - 1; d++)
        {
            maxDiff = max(maxDiff, maxMat[c + 1][d + 1] - mat[c][d]);
        }
    }
    return maxDiff;
}

int main()
{

    return 0;
}