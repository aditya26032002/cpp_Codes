#include <bits/stdc++.h>
using namespace std;

void findFibonacci(int &prev, int &current, int &terminal)
{
    int nextFib = prev + current;
    cout << nextFib << " ";
    if (nextFib >= terminal)
        return;
    prev = current;
    current = nextFib;
    findFibonacci(prev, current, terminal);
}

int main()
{
    int terminal = 12;
    int frstFib = 0, secondFib = 1;
    cout << frstFib << " " << secondFib << " ";
    findFibonacci(frstFib, secondFib, terminal);
    return 0;
}