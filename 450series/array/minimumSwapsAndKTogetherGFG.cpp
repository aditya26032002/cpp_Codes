#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minSwap(int arr[], int n, int k)
    {
        int numOfEls = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] <= k)
                numOfEls++;
        }
        if (numOfEls <= 1 || numOfEls == n)
            return 0;

        int wrongEls = 0;
        for (int i = 0; i < numOfEls; i++)
        {
            if (arr[i] > k)
                wrongEls++;
        }
        int swaps = wrongEls;

        int st = 1;
        int en = numOfEls;
        while (en < n)
        {
            if (arr[st - 1] > k)
                wrongEls--;
            if (arr[en] > k)
                wrongEls++;

            swaps = min(swaps, wrongEls);

            st++;
            en++;
        }

        return swaps;
    }
};

int main()
{

    return 0;
}