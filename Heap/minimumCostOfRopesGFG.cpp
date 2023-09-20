#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n)
    {

        if (n == 1)
            return 0;

        priority_queue<long long, vector<long long>, greater<long long>> minPQ;
        for (long long i = 0; i < n; i++)
            minPQ.push(arr[i]);

        long long ans = 0;
        while (minPQ.size() != 1)
        {
            long long sum = minPQ.top();
            minPQ.pop();
            sum += minPQ.top();
            minPQ.pop();
            minPQ.push(sum);
            ans += sum;
        }
        return ans;
    }
};

int main()
{

    return 0;
}