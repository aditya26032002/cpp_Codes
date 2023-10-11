#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minJumps(int arr[], int n)
    {
        int i = 0;
        int jumps = 0;
        while (i < n)
        {
            if (i + arr[i] >= n - 1)
            {
                jumps++;
                break;
            }

            int maxSteps = arr[i];
            int maxi = arr[i], maxiHop = 0;

            for (int hops = 1; hops <= maxSteps; hops++)
            {
                int el = arr[i + hops];
                if ((el + hops) >= (maxi + maxiHop))
                {
                    maxi = el;
                    maxiHop = hops;
                }
            }

            if (maxiHop == 0)
                return -1;

            i += maxiHop;
            jumps++;
        }
        return jumps;
    }
};

int main()
{

    return 0;
}