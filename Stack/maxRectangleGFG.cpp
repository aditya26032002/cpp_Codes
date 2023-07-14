#include <bits/stdc++.h>
using namespace std;

#define MAX 1000

class Solution
{
public:
    vector<int> getNextSmaller(int arr[], int n)
    {
        vector<int> nxtSmallIndex(n);
        stack<int> st;
        st.push(-1);
        for (int i = n - 1; i >= 0; i--)
        {
            while (st.top() != -1 && arr[st.top()] >= arr[i])
                st.pop();

            nxtSmallIndex[i] = st.top();
            st.push(i);
        }
        return nxtSmallIndex;
    }

    vector<int> getPrevSmaller(int arr[], int n)
    {
        vector<int> prevSmallIndex(n);
        stack<int> st;
        st.push(-1);
        for (int i = 0; i < n; i++)
        {
            while (st.top() != -1 && arr[st.top()] >= arr[i])
                st.pop();

            prevSmallIndex[i] = st.top();
            st.push(i);
        }
        return prevSmallIndex;
    }

    int getAreaOfHistogram(int hist[], int m)
    {
        vector<int> nxtSmall = getNextSmaller(hist, m);
        vector<int> prevSmaller = getPrevSmaller(hist, m);
        int maxArea = 0;
        for (int i = 0; i < m; i++)
        {
            int right = 0;
            int left = 0;
            if (nxtSmall[i] == -1)
            {
                right = m - i;
            }
            else
            {
                right = nxtSmall[i] - i;
            }
            if (prevSmaller[i] == -1)
            {
                left = i;
            }
            else
            {
                left = i - prevSmaller[i] - 1;
            }
            int area = (left + right) * hist[i];
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }

    int maxArea(int M[MAX][MAX], int n, int m)
    {
        int histogram[m] = {0};
        int maxArea = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (M[i][j] == 1)
                    histogram[j]++;
                else
                    histogram[j] = 0;
            }
            int area = getAreaOfHistogram(histogram, m);
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};

int main()
{

    return 0;
}