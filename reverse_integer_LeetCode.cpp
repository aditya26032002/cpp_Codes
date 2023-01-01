#include <bits/stdc++.h>
using namespace std;

int reverse(int x)
{
    int n = x;
    int ans = 0;
    while (n)
    {
        int digit = n % 10;
        if ((ans) <= INT_MAX/10 && (ans) >= INT_MIN/10)
        {
            ans = ans * 10 + digit;
            n /= 10;
        }
        else
            return 0;
    }
    return ans;
}

int main()
{
    int n;
    cout<<"Input n: ";
    cin>>n;
    cout << reverse(n);
    return 0;
}