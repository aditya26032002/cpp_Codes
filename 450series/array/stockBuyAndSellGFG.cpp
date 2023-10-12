#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find the days of buying and selling stock for max profit.
    vector<vector<int>> stockBuySell(vector<int> A, int n)
    {
        vector<vector<int>> ans;
        int s = 0, e = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (A[i] < A[i + 1])
            {
                e = i + 1;
            }
            else
            {
                if (s != e)
                {
                    vector<int> t = {s, e};
                    ans.push_back(t);
                }
                s = e = i + 1;
            }
        }
        if (s != e)
        {
            vector<int> t = {s, e};
            ans.push_back(t);
        }
        return ans;
    }
};

// Stock buy and sell II (GFG)
class Solution
{
public:
    int stockBuyAndSell(int n, vector<int> &prices)
    {
        int s = 0, e = 0, profit = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (prices[i] < prices[i + 1])
                e = i + 1;

            else
            {
                if (s != e)
                    profit += (prices[e] - prices[s]);

                s = e = i + 1;
            }
        }
        if (s != e)
            profit += (prices[e] - prices[s]);

        return profit;
    }
};

int main()
{

    return 0;
}