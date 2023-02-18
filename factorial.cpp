#include <bits/stdc++.h>
using namespace std;

int factOf(int n)
{
    if (n == 0)
        return 1;
    return n * factOf(n - 1);
}

int main()
{
    int n = 0;
    cout << factOf(n);
    return 0;
}