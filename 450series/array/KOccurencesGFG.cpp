#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find all elements in array that appear more than n/k times.
    int countOccurence(int arr[], int n, int k)
    {
        unordered_map<int, int> occurenceMp;
        for (int i = 0; i < n; i++)
        {
            occurenceMp[arr[i]]++;
        }

        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (occurenceMp[arr[i]] > n / k)
            {
                count++;
                occurenceMp[arr[i]] = -1;
            }
        }
        return count;
    }
};

int main()
{

    return 0;
}