#include <bits/stdc++.h>
using namespace std;

// bool checkValidity(string &input, int st, int en)
// {
//     int mid = st + (en - st) / 2;
//     for (int left = mid, right = mid + 1; left >= st && right <= en; left--, right++)
//     {
//         if (input[left] != '(' || input[right] != ')')
//             return false;
//     }
//     return true;
// }

bool checkValidity(string &input, int st, int en)
{
    stack<char> temp;
    while (st <= en)
    {
        if (input[st] == ')' && temp.empty())
            return false;
        else if (input[st] == '(')
        {
            temp.push('(');
        }
        else if (input[st] == ')' && temp.top() == '(')
            temp.pop();
        st++;
    }
    if (temp.empty())
        return true;
    else
        return false;
}

pair<bool, string> isPossible(string &input, int size)
{
    pair<bool, string> ans = {0, ""};
    if (size % 2 != 0)
        return ans;
    int st = 0, en = st + size - 1;
    while (en < input.size())
    {
        if (checkValidity(input, st, en))
        {
            ans.first = true;
            ans.second = input.substr(st, (en - st + 1));
            return ans;
        }
        st++;
        en++;
    }
    return ans;
}

int longestValidParenthesis(string &input)
{
    string ans = "";
    int size = input.size();
    int st = 0, en = size;
    int mid = st + (en - st) / 2;
    while (st <= en)
    {
        if (mid % 2 != 0)
        {
            st++;
            mid = st + (en - st) / 2;
        }
        pair<bool, string> temp = isPossible(input, mid);
        if (temp.first == true)
        {
            if (temp.second.size() > ans.size())
                ans = temp.second;
            st = mid + 1;
        }
        else
        {
            en = mid - 1;
        }
        mid = st + (en - st) / 2;
    }
    cout << ans << endl;
    return ans.size();
}

int main()
{
    // string input = "((())()";
    // string input = "(()";
    string input = "((())((()))";
    // string input = "(())";
    // string input = ")(";
    // string input;
    // cout << "Input string containing '(' & ')'";
    // cin >> input;
    cout << longestValidParenthesis(input);

    return 0;
}