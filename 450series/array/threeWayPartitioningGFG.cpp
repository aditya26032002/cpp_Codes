#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to partition the array around the range such
    // that array is divided into three parts.
    void threeWayPartition(vector<int> &array, int a, int b)
    {
        int less, inrange;
        less = inrange = 0;
        for (int i = 0; i < array.size(); i++)
        {
            if (array[i] < a)
                less++;
            else if (array[i] >= a && array[i] <= b)
                inrange++;
        }
        int lesspt = 0, rangept = less;
        for (int i = 0; i < array.size() && less > 0; i++)
        {
            if (array[i] < a)
            {
                swap(array[i], array[lesspt++]);
                less--;
            }
        }
        for (int i = less; i < array.size() && inrange > 0; i++)
        {
            if (array[i] >= a && array[i] <= b)
            {
                swap(array[i], array[rangept++]);
                inrange--;
            }
        }
    }
};

int main()
{

    return 0;
}