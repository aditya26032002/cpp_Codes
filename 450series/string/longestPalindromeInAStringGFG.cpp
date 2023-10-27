#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Time : O(n^3)    Space : O(1) // Better approach using DP
    pair<bool, int> isPossible(string &S, int size)
    {
        int st = 0, en = size - 1;
        while (en < S.length())
        {
            int tempSt = st, tempEn = en;
            bool possible = true;
            while (tempSt < tempEn)
            {
                if (S[tempSt] != S[tempEn])
                {
                    possible = false;
                    break;
                }
                tempSt++;
                tempEn--;
            }
            if (possible)
                return {true, st};
            st++;
            en++;
        }
        return {false, -1};
    }
    string longestPalin(string S)
    {
        int len = S.length();

        string ans = "";
        ans.push_back(S[0]);

        int ansSt = -1, ansSize;

        for (int i = 2; i <= len; i++)
        {
            pair<bool, int> temp = isPossible(S, i);
            if (temp.first)
            {
                ansSt = temp.second;
                ansSize = i;
            }
        }
        if (ansSt != -1)
            ans = S.substr(ansSt, ansSize);

        return ans;
    }
};

int main()
{

    return 0;
}