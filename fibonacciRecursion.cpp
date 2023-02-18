#include <bits/stdc++.h>
using namespace std;

void findFibonacci(int prev, int current, int terminal)
{
    int nextFib = prev + current;
    cout << nextFib << " ";
    if (nextFib >= terminal)
        return;
    prev = current;
    current = nextFib;
    findFibonacci(prev, current, terminal);
}

// void nthFibonacci(int prev, int current, int currPosition, int terminalPosition)
// {
//     int nextFib = prev + current;
//     currPosition++;
//     if (currPosition == terminalPosition)
//     {
//         cout << nextFib << " ";
//         return;
//     }
//     prev = current;
//     current = nextFib;
//     nthFibonacci(prev, current, currPosition, terminalPosition);
// }

int fib(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return fib(n - 1) + fib(n - 2);
}

int fibIterative(int n)
{
    int frst = 0, scnd = 1;
    int fibo;
    for (int i = 2; i <= n; i++)
    {
        fibo = frst + scnd;
        frst = scnd;
        scnd = fibo;
    }
    return fibo;
}

int main()
{
    int terminal = 12;
    int frstFib = 0, secondFib = 1;
    cout << frstFib << " " << secondFib << " ";
    findFibonacci(frstFib, secondFib, terminal);
    cout << endl
         << endl;

    int n = 6;
    // cout << n << "th fibonacci is ";
    // nthFibonacci(frstFib, secondFib, 2, n);
    // cout << endl << endl;

    // cout << n << "th fibonacci is " << fib(n) << endl;
    cout << n << "th fibonacci is " << fibIterative(n);
    return 0;
}