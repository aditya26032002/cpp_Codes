#include <bits/stdc++.h>
using namespace std;

int checkRedundancy(string s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {

        if (s[i] == ')')
        {
            if (st.top() == '(')
                return 1;
            else
            {
                int count = 0;
                while (1)
                {
                    if (st.top() == '(')
                    {
                        st.pop();
                        break;
                    }
                    st.pop();
                    count++;
                }
                if (count == 1)
                    return 1;
            }
        }
        else
        {
            st.push(s[i]);
        }
    }
    return 0;
}

int main()
{

    return 0;
}