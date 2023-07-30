#include <bits/stdc++.h>
using namespace std;

queue<int> modifyQueue(queue<int> q, int k)
{
    // add code here.
    stack<int> st;
    int size = q.size();
    for (int runtime = 0; runtime < k; runtime++)
    {
        st.push(q.front());
        q.pop();
    }
    while (!st.empty())
    {
        q.push(st.top());
        st.pop();
    }
    for (int runtime = 0; runtime < (size - k); runtime++)
    {
        q.push(q.front());
        q.pop();
    }
    return q;
}

int main()
{

    return 0;
}