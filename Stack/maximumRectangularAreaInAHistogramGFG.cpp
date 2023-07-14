#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find largest rectangular area possible in a given histogram.

    vector<long long> getNextSmaller(long long arr[], int n)
    {
        vector<long long> nxtSmallIndex(n);
        stack<long long> st, index;
        st.push(-1);
        index.push(-1);
        for (long long i = n - 1; i >= 0; i--)
        {
            while (st.top() >= arr[i])
            {
                st.pop();
                index.pop();
            }

            nxtSmallIndex[i] = index.top();
            st.push(arr[i]);
            index.push(i);
        }
        return nxtSmallIndex;
    }

    vector<long long> getPrevSmaller(long long arr[], int n)
    {
        vector<long long> prevSmallIndex(n);
        stack<long long> st, index;
        st.push(-1);
        index.push(-1);
        for (long long i = 0; i < n; i++)
        {
            while (st.top() >= arr[i])
            {
                st.pop();
                index.pop();
            }

            prevSmallIndex[i] = index.top();
            st.push(arr[i]);
            index.push(i);
        }
        return prevSmallIndex;
    }

    long long getMaxArea(long long arr[], int n)
    {
        long long maxArea = 0;
        vector<long long> nextSmaller = getNextSmaller(arr, n);
        vector<long long> prevSmaller = getPrevSmaller(arr, n);

        for (int i = 0; i < n; i++)
        {
            long long right = 0;
            long long left = 0;
            if (nextSmaller[i] == -1)
            {
                right = n - i;
            }
            else
            {
                right = nextSmaller[i] - i;
            }
            if (prevSmaller[i] == -1)
            {
                left = i;
            }
            else
            {
                left = i - prevSmaller[i] - 1;
            }
            long long area = (left + right) * arr[i];
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};

int main()
{

    return 0;
}