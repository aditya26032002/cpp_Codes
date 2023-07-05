#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solve(stack<int> &s, int X)
    {
        if (s.empty())
        {
            s.push(X);
            return;
        }
        int temp = s.top();
        s.pop();
        solve(s, X);
        s.push(temp);
    }
    stack<int> insertAtBottom(stack<int> St, int X)
    {
        solve(St, X);
        return St;
    }
};

int main()
{

    return 0;
}