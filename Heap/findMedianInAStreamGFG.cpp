#include <bits/stdc++.h>
using namespace std;

class Solution
{
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

public:
    // Function to insert heap.
    void insertHeap(int &x)
    {
        if (maxHeap.size() == 0 && minHeap.size() == 0)
        {
            maxHeap.push(x);
            return;
        }

        double currMedian = getMedian();
        if (x > currMedian)
            minHeap.push(x);
        else
            maxHeap.push(x);

        balanceHeaps();
    }

    // Function to balance heaps.
    void balanceHeaps()
    {
        if (abs(minHeap.size() - maxHeap.size()) > 1)
        {
            if (minHeap.size() > maxHeap.size())
            {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
            else
            {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
        }
    }

    // Function to return Median.
    double getMedian()
    {
        if (minHeap.size() > maxHeap.size())
            return minHeap.top();
        else if (maxHeap.size() > minHeap.size())
            return maxHeap.top();
        else
            return (minHeap.top() + maxHeap.top()) / 2.0;
    }
};

int main()
{

    return 0;
}