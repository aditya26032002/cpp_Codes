#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Time : O(2^s)    Space : O(N + s)    // Not optimal solution (Use DP for optimal sol)
    void solve(string &A, int i, unordered_map<string, bool> &dictionary, bool &ans)
    {
        if (i >= A.length())
        {
            ans = true;
            return;
        }

        string temp = "";
        for (; i < A.length(); i++)
        {
            temp.push_back(A[i]);
            if (dictionary.find(temp) != dictionary.end())
            {
                solve(A, i + 1, dictionary, ans);
                if (ans)
                    return;
            }
        }
    }

    int wordBreak(string A, vector<string> &B)
    {
        unordered_map<string, bool> dictionary;
        for (string s : B)
            dictionary[s] = true;

        bool ans = false;
        solve(A, 0, dictionary, ans);
        return ans;
    }
};

int main()
{

    return 0;
}