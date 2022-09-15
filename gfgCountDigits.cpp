#include <iostream>
using namespace std;

int evenlyDivides(int N)
{
    int ans = 0, num = N, digit;
    while (num > 0)
    {
        digit = num % 10;
        if ((digit != 0) && (N % digit == 0))
            ans++;
        num /= 10;
    }
    return ans;
}

int main()
{
    int n = 2207;
    cout<<evenlyDivides(n);
    return 0;
}