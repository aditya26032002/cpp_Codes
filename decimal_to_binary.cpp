#include <iostream>
#include <math.h>
using namespace std;

void binary1(int n)
{
    int quotient, remainder;
    quotient = n / 2;
    remainder = n % 2;

    if (quotient == 0)
    {
        cout << remainder;
        return;
    }
    else
    {
        binary1(quotient);
        cout << remainder;
    }
}

void binary2(int n)
{
    int ans = 0, i = 0;
    while (n != 0)
    {
        int bit = n & 1;
        ans = ans + (bit * pow(10, i));
        n = n >> 1;
        i++;
    }
    cout << ans;
}

int main()
{
    int n;
    cout << "Enter decimal number: ";
    cin >> n;
    binary1(n);
    cout << endl;
    binary2(n);
    return 0;
}