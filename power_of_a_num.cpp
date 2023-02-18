#include <bits/stdc++.h>
using namespace std;

int powerof(int a, int n)
{
    if (n == 0)
        return 1;
    return a * powerof(a, n - 1);
}

int main()
{
    int a = 2, n = -1; // a^n
    float ans;
    if (n >= 0)
        ans = powerof(a, n);
    else
        ans = (float)1 / powerof(a, -n);
    cout << ans;
    return 0;
}