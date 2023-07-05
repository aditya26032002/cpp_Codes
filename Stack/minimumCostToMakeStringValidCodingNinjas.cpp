#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
int countCost(stack<char> &st)
{
    int count = 0;
    while (!st.empty())
    {
        if (st.top() == '{')
        {
            count++;
            st.pop();
            if (st.top() == '}')
            {
                count++;
                st.pop();
            }
            else
                st.pop();
        }
        else
        {
            st.pop();
            if (st.top() == '}')
            {
                count++;
                st.pop();
            }
        }
    }
    return count;
}
int findMinimumCost(string str)
{
    // Write your code here
    stack<char> st;
    for (int i = 0; i < str.length(); i++)
    {
        if (st.empty() || st.top() == '}' || str[i] == '{')
        {
            st.push(str[i]);
        }
        else if (st.top() == '{' && str[i] == '}')
        {
            st.pop();
        }
    }
    if (st.size() % 2 == 0)
        return countCost(st);
    return -1;
}

int main()
{

    return 0;
}