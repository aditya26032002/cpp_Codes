#include <bits/stdc++.h>
using namespace std;

// TLE
void countSubsequences(string &s, string sub, int i, set<string> &storeSubs)
{
    if (i == s.length())
    {
        cout << "Sub: " << sub << endl;
        if (sub.length() != 0)
            storeSubs.insert(sub);
        return;
    }
    // Exclude
    countSubsequences(s, sub, i + 1, storeSubs);
    // Include
    sub.push_back(s[i]);
    countSubsequences(s, sub, i + 1, storeSubs);
}

int distinctSubseqII(string s)
{
    set<string> storeSubs;
    string sub = "";
    countSubsequences(s, sub, 0, storeSubs);
    return storeSubs.size();
}

int main()
{
    // string s = "pcrdhwdxmqdznbenhwjsenjhvulyve"; // TLE
    string s = "aba";
    cout << distinctSubseqII(s);
    return 0;
}