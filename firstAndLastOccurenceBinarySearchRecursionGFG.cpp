#include <bits/stdc++.h>
using namespace std;

long firstOccurence(vector<long long> v, long long x, long s, long e, long ans)
{
    if (s >= e)
    {
        if (v[s] != x)
            return ans;
        else
            return s;
    }
    long mid = s + (e - s) / 2;
    if (v[mid] == x)
    {
        ans = mid;
        return firstOccurence(v, x, s, mid - 1, ans);
    }
    if (v[mid] > x)
        return firstOccurence(v, x, s, mid - 1, ans);
    else
        return firstOccurence(v, x, mid + 1, e, ans);
}

long lastOccurence(vector<long long> v, long long x, int s, int e, long ans)
{
    if (s >= e)
    {
        if (v[s] != x)
            return ans;
        else
            return s;
    }
    long mid = s + (e - s) / 2;
    if (v[mid] == x)
    {
        ans = mid;
        return lastOccurence(v, x, mid + 1, e, ans);
    }
    if (v[mid] > x)
        return lastOccurence(v, x, s, mid - 1, ans);
}

pair<long, long> indexes(vector<long long> v, long long x)
{
    pair<long, long> ans;
    ans.first = firstOccurence(v, x, 0, v.size() - 1, -1);
    if (ans.first == -1)
    {
        ans.second = -1;
        return ans;
    }
    else
    {
        ans.second = lastOccurence(v, x, ans.first, v.size() - 1, ans.first);
        return ans;
    }
}

int main()
{
    // vector<long long> v = {1, 3, 4, 4, 4, 4, 67, 123, 125};
    // vector<long long> v = {1, 3, 5, 5, 5, 5, 67, 123, 125};
    // long long x = 5;
    vector<long long> v = {1, 1, 3, 4, 4, 5, 5};
    long long x = 1;
    pair<long, long> ans = indexes(v, x);
    cout << ans.first << " " << ans.second << endl;
    return 0;
}