#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Time : O(n! * n) Space : O(n! * n)
    void solve(string &inp, string prod, vector<string> &ans)
    {
        if (prod.length() == inp.length())
        {
            ans.push_back(prod);
            return;
        }
        for (int i = 0; i < inp.size(); i++)
        {
            if (inp[i] != '*')
            {
                char temp = inp[i];
                inp[i] = '*';
                prod.push_back(temp);
                solve(inp, prod, ans);
                inp[i] = temp;
                prod.pop_back();
            }
        }
    }
    vector<string> find_permutation(string S)
    {
        vector<string> tempAns;
        solve(S, "", tempAns);
        sort(tempAns.begin(), tempAns.end());
        vector<string> ans;
        for (int i = 0; i < tempAns.size(); i++)
        {
            if (i + 1 < tempAns.size() && tempAns[i] == tempAns[i + 1])
                continue;
            else
                ans.push_back(tempAns[i]);
        }
        return ans;
    }
};

int main()
{

    return 0;
}