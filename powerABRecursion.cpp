#include <bits/stdc++.h>
using namespace std;

int power(int a, int b)
{
    if (b == 0)
        return 1;

    int temp = power(a, b / 2);
    if (!(b & 1))
        return temp * temp;
    else
        return a * temp * temp;
}

int main()
{
    cout << power(3, 3) << endl;
    return 0;
}