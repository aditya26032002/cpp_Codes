#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int ans = 0, purchase = INT_MAX, sell = INT_MIN;
        for (int i = 0; i < prices.size(); i++)
        {
            if (prices[i] < purchase)
            {
                purchase = prices[i];
                sell = purchase;
            }
            else if (prices[i] > sell)
            {
                sell = prices[i];
            }
            ans = max(ans, sell - purchase);
        }
        return ans;
    }
};

int main()
{

    return 0;
}