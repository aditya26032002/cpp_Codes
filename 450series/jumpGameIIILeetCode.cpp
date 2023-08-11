#include <bits/stdc++.h>
using namespace std;

bool canReach(vector<int> &arr, int start)
{
    if (start >= 0 && start < arr.size() && arr[start] >= 0)
    {
        if (arr[start] == 0)
        {
            return true;
        }
        arr[start] = -arr[start];
        return canReach(arr, start + arr[start]) || canReach(arr, start - arr[start]);
    }
    return false;
}

/*
void jump(vector<int> &arr, int curr, bool &ans, set<int> &path)
{
    if (ans == true || arr[curr] == 0)
    {
        ans = true;
        return;
    }

    if (path.find(curr) != path.end())
    {
        return;
    }
    else
        path.insert(curr);

    int next = curr + arr[curr];
    int prev = curr - arr[curr];
    if (next < arr.size())
    {
        jump(arr, next, ans, path);
    }
    if (prev >= 0)
    {
        jump(arr, prev, ans, path);
    }
    path.erase(path.find(curr));
}
bool canReach(vector<int> &arr, int start)
{
    bool ans = false;
    set<int> path;
    jump(arr, start, ans, path);
    return ans;
}
*/

int main()
{

    return 0;
}