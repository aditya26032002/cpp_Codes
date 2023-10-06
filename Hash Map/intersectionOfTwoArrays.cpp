#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to return the count of the number of elements in
    // the intersection of two arrays.
    int NumberofElementsInIntersection(int a[], int b[], int n, int m)
    {
        // Your code goes here
        unordered_map<int, bool> mp;
        int countSimilar = 0;

        for (int i = 0; i < n; i++)
        {
            mp[a[i]] = true;
        }
        for (int i = 0; i < m; i++)
        {
            if (mp[b[i]])
            {
                countSimilar++;
                mp[b[i]] = false;
            }
        }

        return countSimilar;
    }
};

int main()
{

    return 0;
}