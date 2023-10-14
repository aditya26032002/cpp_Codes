#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Time : O(n)  Space : O(n)
    void rearrange(int arr[], int n)
    {
        vector<int> pos, neg;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] < 0)
                neg.push_back(arr[i]);
            else
                pos.push_back(arr[i]);
        }
        bool putPos = true;
        int i = 0, posPtr = 0, negPtr = 0;
        while (posPtr < pos.size() && negPtr < neg.size())
        {
            if (putPos)
            {
                arr[i++] = pos[posPtr++];
                putPos = false;
            }
            else
            {
                arr[i++] = neg[negPtr++];
                putPos = true;
            }
        }
        while (posPtr < pos.size())
            arr[i++] = pos[posPtr++];

        while (negPtr < neg.size())
            arr[i++] = neg[negPtr++];
    }

    // Time : O(n^2)    Space : O(1)
    void rearrange(int arr[], int n)
    {
        int pos = 0, neg = 0;
        while (pos < n && neg < n)
        {
            while (pos < n && arr[pos] < 0)
                pos++;

            while (neg < n && arr[neg] >= 0)
                neg++;

            if (pos == n || neg == n)
                break;

            int tempPos = pos, tempNeg = neg;
            if (neg < pos)
            {
                while (pos > neg)
                {
                    swap(arr[pos], arr[pos - 1]);
                    pos--;
                }
                neg = tempNeg + 2;
                pos = tempPos + 1;
            }
            else
            {
                while (neg > pos + 1)
                {
                    swap(arr[neg], arr[neg - 1]);
                    neg--;
                }
                pos += 2;
                neg = tempNeg + 1;
            }
        }
    }
};

int main()
{

    return 0;
}