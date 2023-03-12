#include <bits/stdc++.h>
using namespace std;

void solve(string &digits, string sub, string keymap[], vector<string> &ans, int i)
{
    if (i == digits.length())
    {
        if (sub.length() > 0)
            ans.push_back(sub);
        return;
    }
    for (char c : (keymap[digits[i] - '0']))
    {
        sub.push_back(c);
        solve(digits, sub, keymap, ans, i + 1);
        sub.pop_back();
    }
}

vector<string> letterCombinations(string digits)
{
    string keymap[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> ans;
    solve(digits, "", keymap, ans, 0);
    return ans;
}

int main()
{
    string digits = "7879";
    vector<string> ans = letterCombinations(digits);
    for (auto i : ans)
        cout << i << endl;
    return 0;
}

// void solve(string &digits, string sub, map<char, string> &keymap, vector<string> &ans, int i)
// {
//     if (i == digits.length())
//     {
//         if (sub.length() > 0)
//             ans.push_back(sub);
//         return;
//     }
//     for (char c : keymap[digits[i]])
//     {
//         string temp = sub;
//         temp.push_back(c);
//         solve(digits, temp, keymap, ans, i + 1);
//     }
// }

// vector<string> letterCombinations(string digits)
// {
//     map<char, string> keymap;
//     keymap['2'] = "abc";
//     keymap['3'] = "def";
//     keymap['4'] = "ghi";
//     keymap['5'] = "jkl";
//     keymap['6'] = "mno";
//     keymap['7'] = "pqrs";
//     keymap['8'] = "tuv";
//     keymap['9'] = "wxyz";
//     vector<string> ans;
//     solve(digits, "", keymap, ans, 0);
//     return ans;
// }