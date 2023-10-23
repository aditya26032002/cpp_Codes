#include <bits/stdc++.h>
using namespace std;

#define MAX 1000

class Solution
{
public:
    // Time : O(n*m)    Space : O(m)
    int helper(int towers[], stack<int> &st, int &i)
    {
        while (!st.empty() && towers[st.top()] >= towers[i])
            st.pop();

        int ans;
        if (st.empty())
            ans = -1;
        else
            ans = st.top();

        st.push(i);
        return ans;
    }

    void getNextAndPrevSmaller(int towers[], int nextSmaller[], int prevSmaller[], int &size)
    {
        stack<int> st1;
        for (int i = size - 1; i >= 0; i--)
        {
            int nxt = helper(towers, st1, i);
            if (nxt == -1)
                nextSmaller[i] = size;
            else
                nextSmaller[i] = nxt;
        }

        stack<int> st2;
        for (int i = 0; i < size; i++)
            prevSmaller[i] = helper(towers, st2, i);
    }

    int getArea(int towers[], int &size)
    {
        int nxtSmaller[size], prevSmaller[size];
        getNextAndPrevSmaller(towers, nxtSmaller, prevSmaller, size);
        int maxArea = 0;
        for (int i = 0; i < size; i++)
        {
            int currArea = towers[i] * (nxtSmaller[i] - prevSmaller[i] - 1);
            maxArea = max(maxArea, currArea);
        }
        return maxArea;
    }

    int maxArea(int M[MAX][MAX], int n, int m)
    {
        int area = 0;
        int towers[m] = {0};
        for (int r = 0; r < n; r++)
        {
            for (int c = 0; c < m; c++)
            {
                if (M[r][c] == 0)
                    towers[c] = 0;
                else
                    towers[c]++;
            }

            int currArea = getArea(towers, m);
            area = max(area, currArea);
        }
        return area;
    }
};

int main()
{

    return 0;
}