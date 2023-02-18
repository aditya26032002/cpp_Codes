#include <bits/stdc++.h>
using namespace std;

// TLE because DP is not used
int countDistinctWays(int nStairs)
{
    if (nStairs < 0)
        return 0;
    if (nStairs == 0)
        return 1;
    return countDistinctWays(nStairs - 1) + countDistinctWays(nStairs - 2);
}

int main()
{
    int n = 4;
    cout << countDistinctWays(n);
    return 0;
}