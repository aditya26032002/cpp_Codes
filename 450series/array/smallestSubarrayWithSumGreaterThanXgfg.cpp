#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int smallestSubWithSum(int arr[], int n, int x)
    {
        int st, en, sum, ans = n;
        st = en = sum = 0;
        while (en < n)
        {
            if (arr[en] > x)
                return 1;
            sum += arr[en];
            if (sum > x)
            {
                while (st < en)
                {
                    if (sum - arr[st] <= x)
                        break;
                    sum -= arr[st];
                    st++;
                }
                ans = min(ans, en - st + 1);
            }
            en++;
        }
        if (sum <= x)
            return 0;
        return ans;
    }
};

int main()
{

    return 0;
}