#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Time : O(n^2)
    // int celebrity(vector<vector<int>> &M, int n)
    // {
    //     for (int i = 0; i < 2; i++)
    //     {
    //         for (int j = 0; j < n; j++)
    //         {
    //             if (M[i][j] == 1)
    //             {
    //                 bool flag = 1;
    //                 for (int x = 0; x < n; x++)
    //                 {
    //                     if (x != j && M[x][j] == 0)
    //                     {
    //                         flag = 0;
    //                         break;
    //                     }
    //                 }
    //                 if (flag)
    //                 {
    //                     for (int x = 0; x < n; x++)
    //                     {
    //                         if (M[j][x] == 1)
    //                         {
    //                             flag = 0;
    //                             break;
    //                         }
    //                     }
    //                     if (flag)
    //                         return j;
    //                 }
    //             }
    //         }
    //     }
    //     return -1;
    // }

    // Time: O(n), Space: O(n)
    int celebrity(vector<vector<int>> &M, int n)
    {
        stack<int> st;
        for (int i = 0; i < n; i++)
            st.push(i);
        while (st.size() != 1)
        {
            int A = st.top();
            st.pop();
            int B = st.top();
            st.pop();
            if (M[A][B] == 1)
                st.push(B);
            else
                st.push(A);
        }
        int x = st.top();
        for (int j = 0; j < n; j++)
        {
            if (M[x][j] == 1)
                return -1;
        }
        for (int i = 0; i < n; i++)
        {
            if (M[i][x] == 0 && i != x)
                return -1;
        }
        return x;
    }
};

int main()
{

    return 0;
}