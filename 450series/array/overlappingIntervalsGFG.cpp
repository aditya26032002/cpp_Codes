#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void updateInterval(vector<vector<int>> &intervals, int &i, int &start, int &end)
    {
        if (i >= intervals.size() || intervals[i][0] > end)
            return;

        start = min(start, intervals[i][0]);
        end = max(end, intervals[i][1]);
        updateInterval(intervals, ++i, start, end);
    }

    vector<vector<int>> overlappedInterval(vector<vector<int>> &intervals)
    {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        int i = 0;
        while (i < intervals.size())
        {
            int st = intervals[i][0];
            int en = intervals[i][1];
            updateInterval(intervals, ++i, st, en);
            vector<int> updatedInterval = {st, en};
            ans.push_back(updatedInterval);
        }
        return ans;
    }
};

int main()
{

    return 0;
}