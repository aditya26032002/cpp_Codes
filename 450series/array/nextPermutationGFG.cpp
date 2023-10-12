#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Time : O(n)  Space : O(1)
    vector<int> nextPermutation(int N, vector<int> arr)
    {
        int index = -1;
        for (int i = 0; i < N; i++)
        {
            if (i > 0 && (arr[i] > arr[i - 1]))
                index = i - 1;
        }

        if (index == -1)
        {
            reverse(arr.begin(), arr.end());
            return arr;
        }

        int i = N - 1;
        for (; i > index; i--)
        {
            if (arr[i] > arr[index])
                break;
        }

        swap(arr[index], arr[i]);
        reverse(arr.begin() + index + 1, arr.end());

        return arr;
    }
};

int main()
{

    return 0;
}