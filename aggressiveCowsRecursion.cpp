#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &stalls, int cows, int minDist)
{
    int prevPos = stalls[0];
    cows--;
    for (int i = 1; i < stalls.size(); i++)
    {
        if (stalls[i] - prevPos >= minDist)
        {
            prevPos = stalls[i];
            cows--;
            if (cows == 0)
                return true;
        }
    }
    return false;
}

int binarySearch(vector<int> &stalls, int cows, int s, int e, int ans)
{
    if (s > e)
        return ans;
    int mid = s + (e - s) / 2;
    if (isPossible(stalls, cows, mid))
    {
        if (mid > ans)
            ans = mid;
        return binarySearch(stalls, cows, mid + 1, e, ans);
    }
    else
        return binarySearch(stalls, cows, s, mid - 1, ans);
}

int solve(int n, int k, vector<int> &stalls)
{
    sort(stalls.begin(), stalls.end());
    int s = 0, e = stalls[n - 1];
    return binarySearch(stalls, k, s, e, 0);
}

int main()
{
    vector<int> stalls = {10, 1, 2, 7, 5};
    int cows = 3;
    cout << solve(stalls.size(), cows, stalls);
    return 0;
}