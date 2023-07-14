#include <bits/stdc++.h>
using namespace std;

// #include <stack>

// void sortedPush(stack<int> &st, int x)
// {
//     if (st.empty() || st.top() < x)
//     {
//         st.push(x);
//         return;
//     }

//     int temp = st.top();
//     st.pop();
//     sortedPush(st, x);
//     st.push(temp);
// }

// void findNextSmaller(stack<int> &st, int element, int &ans)
// {
//     if (st.empty())
//     {
//         ans = -1;
//         return;
//     }
//     if (st.top() < element)
//     {
//         ans = st.top();
//         return;
//     }

//     int temp = st.top();
//     st.pop();
//     findNextSmaller(st, element, ans);
//     st.push(temp);
// }

// vector<int> nextSmallerElement(vector<int> &arr, int n)
// {
//     vector<int> ans(n);
//     ans[n - 1] = -1;
//     stack<int> st;
//     for (int i = n - 2; i >= 0; i--)
//     {
//         sortedPush(st, arr[i + 1]);
//         findNextSmaller(st, arr[i], ans[i]);
//     }
//     return ans;
// }

#include <stack>

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    vector<int> ans(n, -1);
    stack<int> st;
    st.push(-1);
    for (int i = n - 1; i >= 0; i--)
    {
        while (st.top() >= arr[i])
        {
            st.pop();
        }
        ans[i] = st.top();
        st.push(arr[i]);
    }
    return ans;
}

int main()
{

    return 0;
}