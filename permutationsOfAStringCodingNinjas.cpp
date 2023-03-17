#include <bits/stdc++.h>
using namespace std;

void solve(string sub, int index, vector<string> &ans)
{
    if (index == sub.length())
    {
        ans.push_back(sub);
        return;
    }
    for (int j = index; j < sub.length(); j++)
    {
        swap(sub[index], sub[j]);
        solve(sub, index + 1, ans);
        swap(sub[index], sub[j]);
    }
}

vector<string> generatePermutations(string &str)
{
    vector<string> ans;
    solve(str, 0, ans);
    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{
    string input = "bca";
    vector<string> ans = generatePermutations(input);
    for (auto i : ans)
        cout << i << endl;
    return 0;
}

// void solve(string &str, string sub, vector<string> &ans, int putCount, int putArr[])
// {
//     if (putCount == str.length())
//     {
//         ans.push_back(sub);
//         return;
//     }
//     for (int i = 0; i < str.length(); i++)
//     {
//         if (putArr[i] != 1)
//         {
//             sub.push_back(str[i]);
//             putArr[i] = 1;
//             solve(str, sub, ans, putCount + 1, putArr);
//             sub.pop_back();
//             putArr[i] = 0;
//         }
//     }
// }

// vector<string> generatePermutations(string &str)
// {
//     int putArr[10] = {0};
//     vector<string> ans;
//     solve(str, "", ans, 0, putArr);
//     return ans;
// }