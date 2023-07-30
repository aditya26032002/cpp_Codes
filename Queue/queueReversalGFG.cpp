#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solve(queue<int> &q)
    {
        if (q.empty())
            return;

        int temp = q.front();
        q.pop();
        solve(q);
        q.push(temp);
    }
    queue<int> rev(queue<int> q)
    {
        solve(q);
        return q;
    }

    // queue<int> rev(queue<int> q)
    // {
    //     stack<int> st;
    //     while(!q.empty())
    //     {
    //         st.push(q.front());
    //         q.pop();
    //     }
    //     while(!st.empty())
    //     {
    //         q.push(st.top());
    //         st.pop();
    //     }
    //     return q;
    // }
};

int main()
{

    return 0;
}