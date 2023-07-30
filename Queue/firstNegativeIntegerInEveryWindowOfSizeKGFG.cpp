#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int A[],
                                            long long int N, long long int K)
{

    vector<long long> ans;
    queue<long long> negative, window;
    for (int i = 0; i < K; i++)
    {
        if (A[i] < 0)
            negative.push(A[i]);
        window.push(A[i]);
    }
    if (negative.empty())
        ans.push_back(0);
    else
        ans.push_back(negative.front());
    for (int en = K; en < N; en++)
    {
        if (A[en] < 0)
            negative.push(A[en]);
        window.push(A[en]);

        if (!negative.empty() && negative.front() == window.front())
        {
            negative.pop();
            window.pop();
        }
        else
            window.pop();

        if (negative.empty())
            ans.push_back(0);
        else
            ans.push_back(negative.front());
    }
    return ans;
}

int main()
{

    return 0;
}