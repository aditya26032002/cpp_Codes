#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Time : O(min(logN, logM))    Space : O(1)
    bool bothArrayAreSeparateSorted(vector<int> &array1, vector<int> &array2, double &ans)
    {
        int a1Size = array1.size(), a2Size = array2.size();
        if (array1[a1Size - 1] < array2[0])
        {
            int totSize = a1Size + a2Size;
            if (totSize & 1) // odd
            {
                int mid = (totSize + 1) / 2;
                if (a1Size >= mid)
                    ans = (double)array1[mid - 1];
                else
                    ans = (double)array2[mid - a1Size - 1];
            }
            else
            {
                int mid1 = (totSize) / 2;
                int mid2 = mid1 + 1;
                double mid1Val, mid2Val;
                if (mid1 <= a1Size)
                    mid1Val = array1[mid1 - 1];
                else
                    mid1Val = array2[mid1 - a1Size - 1];

                if (mid2 <= a1Size)
                    mid2Val = array2[mid2 - 1];
                else
                    mid2Val = array2[mid2 - a1Size - 1];
                ans = (double)(mid1Val + mid2Val) / 2;
            }
            return true;
        }
        return false;
    }

    void solve(vector<int> &ar1, vector<int> &ar2, double &ans)
    {
        int totSize = ar1.size() + ar2.size();
        int n = totSize / 2;
        int st = 0, en = ar1.size();
        while (st <= en)
        {
            int a1Size = st + (en - st) / 2;
            int a2Size = n - a1Size;
            int l1, l2, r1, r2;
            if (a1Size == 0)
                l1 = INT_MIN;
            else
                l1 = ar1[a1Size - 1];

            l2 = ar2[a2Size - 1];
            if (a1Size == ar1.size())
                r1 = INT_MAX;
            else
                r1 = ar1[a1Size];
            r2 = ar2[a2Size];

            int leftMax = max(l1, l2);
            int rightMin = min(r1, r2);
            if (leftMax <= rightMin)
            {
                if (totSize & 1)
                    ans = rightMin;
                else
                    ans = (double)(leftMax + rightMin) / 2;
                return;
            }
            else
            {
                if (l1 > r2)
                    en = a1Size - 1;
                else
                    st = a1Size + 1;
            }
        }
    }

    double MedianOfArrays(vector<int> &array1, vector<int> &array2)
    {
        double ans;
        if (array1.size() == 0)
        {
            int s2 = array2.size();
            if (s2 & 1)
                return array2[(s2 + 1) / 2 - 1];
            else
                return (double)(array2[(s2) / 2 - 1] + array2[(s2) / 2]) / 2;
        }
        if (array2.size() == 0)
        {
            int s1 = array1.size();
            if (s1 & 1)
                return array1[(s1 + 1) / 2 - 1];
            else
                return (double)(array1[(s1) / 2 - 1] + array1[(s1) / 2]) / 2;
        }
        bool temp1 = bothArrayAreSeparateSorted(array1, array2, ans);
        bool temp2 = bothArrayAreSeparateSorted(array2, array1, ans);
        if (temp1 || temp2)
            return ans;

        if (array1.size() < array2.size())
            solve(array1, array2, ans);
        else
            solve(array2, array1, ans);

        return ans;
    }
};

int main()
{
    return 0;
}