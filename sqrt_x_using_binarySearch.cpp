#include <bits/stdc++.h>
using namespace std;

int sqrtInteger(int x) // O(log n)
{
    if (x == 0)
    {
        return 0;
    }
    int ans = 1;
    int s = 1, e = x;
    int m = s + (e - s) / 2;
    while (s < e)
    {
        if (m <= x / m && (m + 1) >= x / (m + 1))
        {
            ans = m;
            break;
        }
        else if (m < x / m)
            s = m + 1;
        else
            e = m;
        m = s + (e - s) / 2;
    }
    return ans;
}

// O(log 10^precision)
double morePrecise(int x, int precision, int tempSol)
{
    double factor = 1;
    for (int i = 0; i < precision; i++)
    {
        factor /= 10;
    }
    double ans = tempSol;
    double s = 0.000, e = 1.000;
    double m = s + (e - s) / 2;
    while (s <= e)
    {
        long double square = (tempSol + m) * (tempSol + m);
        if (square == x)
        {
            ans = (tempSol + m);
            break;
        }
        else if (square < x)
        {
            ans = tempSol + m;
            s = m + factor;
        }
        else
        {
            e = m - factor;
        }
        m = s + (e - s) / 2;
    }
    return ans;
}

int main()
{
    int x = 1;
    int tempSol = sqrtInteger(x);
    cout << morePrecise(x, 5, tempSol) << endl;
    return 0;
}

// O(n)
// double morePrecise(int x, int precision, int tempSol)
// {
//     double factor = 1;
//     double ans = tempSol;
//     for (int i = 0; i < precision; i++)
//     {
//         factor /= 10;

//         for (double j = ans; j * j < x; j += factor)
//         {
//             ans = j;
//         }
//     }
//     return ans;
// }