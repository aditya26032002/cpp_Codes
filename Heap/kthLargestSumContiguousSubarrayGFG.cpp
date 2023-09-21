#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Time : O(n^2 Log(k)) Space : O(k)
    int kthLargest(vector<int> &Arr, int N, int K)
    {
        priority_queue<int, vector<int>, greater<int>> minPQ;
        for (int i = 0; i < N; i++)
        {
            int sum = 0;
            for (int j = i; j < N; j++)
            {
                sum += Arr[j];
                if (minPQ.size() < K)
                    minPQ.push(sum);
                else if (sum > minPQ.top())
                {
                    minPQ.pop();
                    minPQ.push(sum);
                }
            }
        }
        while (minPQ.size() > K)
            minPQ.pop();

        return minPQ.top();
    }
    /*
    // Time : O(n^2 Log(n)) Space : O(n^2)
    int kthLargest(vector<int> &Arr, int N, int K)
    {
        vector<int> sumOfSubs;
        for (int i = 0; i < N; i++)
        {
            int sum = 0;
            for (int j = i; j < N; j++)
            {
                sum += Arr[j];
                sumOfSubs.push_back(sum);
            }
        }
        sort(sumOfSubs.begin(), sumOfSubs.end());
        return sumOfSubs[sumOfSubs.size() - K];
    }
    */
};

int main()
{

    return 0;
}