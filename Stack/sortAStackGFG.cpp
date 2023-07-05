#include <bits/stdc++.h>
using namespace std;

class SortedStack
{
public:
    stack<int> s;
    void sort();
};

/* The below method sorts the stack s
you are required to complete the below method */
void putAtRightPosition(stack<int> &st, int x)
{
    if (st.empty() || st.top() <= x)
    {
        st.push(x);
        return;
    }

    int temp = st.top();
    st.pop();
    putAtRightPosition(st, x);
    st.push(temp);
}
void SortedStack ::sort()
{
    if (s.empty())
        return;

    int temp = s.top();
    s.pop();
    sort();
    putAtRightPosition(s, temp);
}

int main()
{

    return 0;
}