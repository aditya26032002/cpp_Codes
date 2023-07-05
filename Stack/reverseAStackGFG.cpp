#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void insertAtBottom(stack<int> &st, int x)
    {
        if (st.empty())
        {
            st.push(x);
            return;
        }
        int temp = st.top();
        st.pop();
        insertAtBottom(st, x);
        st.push(temp);
    }
    void reverse(stack<int> &st)
    {
        if (st.empty())
            return;

        int temp = st.top();
        st.pop();
        reverse(st);
        insertAtBottom(st, temp);
    }
    void Reverse(stack<int> &St)
    {
        reverse(St);
    }
};

int main()
{

    return 0;
}