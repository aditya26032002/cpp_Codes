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