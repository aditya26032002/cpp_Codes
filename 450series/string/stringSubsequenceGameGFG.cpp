#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Time : O(n*Logn*2^n) Space : O(2^n)
    bool isVowel(char s)
    {
        vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        for (char i : vowels)
            if (i == s)
                return true;
        return false;
    }

    void solve(string &S, int i, string sub, set<string> &ans)
    {
        for (int j = i + 1; j < S.length(); j++)
        {
            string temp = sub + S[j];
            if (!isVowel(S[j]))
                ans.insert(temp);
            solve(S, j, temp, ans);
        }
    }
    set<string> allPossibleSubsequences(string S)
    {
        set<string> ans;
        for (int i = 0; i < S.length(); i++)
        {
            if (!isVowel(S[i]))
                continue;
            string temp = "";
            temp.push_back(S[i]);
            solve(S, i, temp, ans);
        }
        return ans;
    }
};

int main()
{

    return 0;
}