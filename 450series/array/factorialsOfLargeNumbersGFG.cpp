#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void multiplyAndUpdateArr(int num, vector<int> &ans)
    {
        int carry = 0;
        for (int i = 0; i < ans.size(); i++)
        {
            int res = (ans[i] * num) + carry;
            ans[i] = res % 10;
            carry = res / 10;
        }
        if (carry != 0)
        {
            while (carry)
            {
                ans.push_back(carry % 10);
                carry /= 10;
            }
        }
    }
    vector<int> factorial(int N)
    {
        vector<int> ans = {1};
        if (N == 1)
            return ans;

        for (int i = 2; i <= N; i++)
        {
            multiplyAndUpdateArr(i, ans);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{

    return 0;
}