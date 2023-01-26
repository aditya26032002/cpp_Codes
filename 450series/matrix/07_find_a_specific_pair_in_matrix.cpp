#include <bits/stdc++.h>
using namespace std;

#define N 5

// O(n^4)
int findMaxDiff(int mat[][N])
{
    int max = INT_MIN;
    for (int a = 0; a < N - 1; a++)
    {
        for (int b = 0; b < N - 1; b++)
        {
            for (int c = a + 1; c < N; c++)
            {
                for (int d = b + 1; d < N; d++)
                {
                    int diff = abs(mat[c][d] - mat[a][b]);
                    if (diff > max)
                        max = diff;
                }
            }
        }
    }
    return max;
}

int main()
{
    int mat[N][N] = {{1, 2, -1, -4, -20},
                     {-8, -3, 4, 2, 1},
                     {3, 8, 6, 1, 3},
                     {-4, -1, 1, 7, -6},
                     {0, -4, 10, -5, 1}};
    cout << findMaxDiff(mat);
    return 0;
}