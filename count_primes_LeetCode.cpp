#include <bits/stdc++.h>
using namespace std;

int countPrimes(int n)
{
    int count = 0;
    vector<bool> prime(n + 1, true);
    for (int i = 2; i < n; i++)
    {
        if (prime[i])
        {
            count++;
            for (int j = 2; j * i <= n; j++)
            {
                prime[j * i] = false;
            }
        }
    }
    return count;
}

int main()
{
    int n;
    cin >> n;
    cout << countPrimes(n);
    return 0;
}