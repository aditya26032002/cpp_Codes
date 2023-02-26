#include <bits/stdc++.h>
using namespace std;

long long int floorSqrt(long long int x, long long int s, long long int e)
{
    long long int mid = s + (e - s) / 2;
    if ((mid * mid) <= x && ((mid + 1) * (mid + 1)) > x)
        return mid;
    if ((mid + 1) * (mid + 1) <= x)
        return floorSqrt(x, mid + 1, e);
    else
        return floorSqrt(x, s, mid - 1);
}

int main()
{
    long long int x = 10000000;
    cout << floorSqrt(x, 1, x);
    return 0;
}