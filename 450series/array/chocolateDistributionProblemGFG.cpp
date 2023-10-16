#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long findMinDiff(vector<long long> a, long long n, long long m)
    {
        sort(a.begin(), a.end());
        long long i = 0, ans = a[n - 1] - a[0];
        while (i + m - 1 < n)
        {
            long long diff = a[i + m - 1] - a[i];
            ans = min(ans, diff);
            i++;
        }
        return ans;
    }
};

int main()
{

    return 0;
}