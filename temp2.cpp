#include <bits/stdc++.h>
using namespace std;

int times = 0;
int findCombination(int n, int r)
{

    // calculate the number of times the function is called
    times++;
    cout << "Called " << times << " times" << endl;

    if (r == 0 || n == r)
    {
        return 1;
    }
    return findCombination(n - 1, r - 1) + findCombination(n - 1, r);
}

// time complexity: O(2^n)

int main()
{
    int n = 1000;
    int r = 495;
    cout << findCombination(n, r) << endl;

    return 0;
}