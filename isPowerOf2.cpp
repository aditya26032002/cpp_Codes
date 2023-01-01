#include <bits/stdc++.h>
using namespace std;

bool isPowerOfTwo(int n)
{
    bool ans = false;
    int i = 0;
    while ((1 <= (INT_MAX / (1 << i))) && ((1 << i) <= n) && (n >= 1))
    {
        if ((1 << i) == n)
            ans = true;
        i++;
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    cout << isPowerOfTwo(n);
    return 0;
}