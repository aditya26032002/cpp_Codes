#include <bits/stdc++.h>
using namespace std;

void print(int n)
{
    cout << n << " ";
    if (n == 0)
    {
        return;
    }
    print(n - 1);
}

int main()
{
    int n = 10;
    print(n);
    return 0;
}