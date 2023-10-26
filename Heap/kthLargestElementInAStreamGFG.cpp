#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> kthLargest(int k, int arr[], int n)
    {
        priority_queue<int, vector<int>, greater<int>> minHeap, toRemove;
        vector<int> ans;
        int i = 0;
        for (; i < k - 1; i++)
        {
            ans.push_back(-1);
            minHeap.push(arr[i]);
        }
        minHeap.push(arr[i++]);
        ans.push_back(minHeap.top());
        for (; i < n; i++)
        {
            toRemove.push(arr[i - k]);
            minHeap.push(arr[i]);

            if (minHeap.size() > k)
            {
                if (minHeap.top() == toRemove.top())
                {
                    minHeap.pop();
                    toRemove.pop();
                }
                else
                    minHeap.pop();
            }

            ans.push_back(minHeap.top());
        }
        return ans;
    }
};

int main()
{

    return 0;
}