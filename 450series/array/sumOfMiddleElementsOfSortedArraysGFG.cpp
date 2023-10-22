#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Time : O(LogN)   Space : O(1)
    int findMidSum(int ar1[], int ar2[], int n)
    {
        if (ar1[n - 1] < ar2[0])
            return ar1[n - 1] + ar2[0];

        if (ar1[0] > ar2[n - 1])
            return ar1[0] + ar2[n - 1];

        int st = 0, en = n;

        while (st <= en)
        {
            int a1Size = st + (en - st) / 2;
            int a2Size = n - a1Size;
            int pt1 = a1Size - 1, pt2 = a2Size - 1;
            int pt3 = a1Size, pt4 = a2Size;

            int leftMax = max(ar1[pt1], ar2[pt2]);
            int rightMin = min(ar1[pt3], ar2[pt4]);
            if (leftMax <= rightMin)
                return leftMax + rightMin;
            else
            {
                if (ar1[pt1] != ar2[pt2])
                {
                    if (leftMax == ar1[pt1])
                        en = a1Size - 1;
                    else
                        st = a1Size + 1;
                }
                else
                {
                    if (rightMin == ar1[pt3])
                        st = a1Size + 1;
                    else
                        en = a1Size - 1;
                }
            }
        }
    }
    /*
    // Time : O(n)  Space : O(1)
    int findMidSum(int ar1[], int ar2[], int n)
    {
        for (int i = n - 1, j = 0; i >= 0; i--, j++)
        {
            if (ar1[i] > ar2[j])
                swap(ar1[i], ar2[j]);
            else
                break;
        }
        int firstArrMax = INT_MIN, secondArrMin = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            firstArrMax = max(firstArrMax, ar1[i]);
            secondArrMin = min(secondArrMin, ar2[i]);
        }
        return firstArrMax + secondArrMin;
    }
    */
};

int main()
{

    return 0;
}