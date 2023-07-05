#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        stack<char> st;
        for (int i = 0; i < x.length(); i++)
        {
            if (st.empty() || x[i] == '{' || x[i] == '[' || x[i] == '(')
                st.push(x[i]);
            else if (st.top() == '{' && x[i] == '}')
                st.pop();
            else if (st.top() == '[' && x[i] == ']')
                st.pop();
            else if (st.top() == '(' && x[i] == ')')
                st.pop();
            else
                return false;
        }
        if (st.empty())
            return true;
    }
};

int main()
{

    return 0;
}