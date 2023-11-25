#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string secFrequent(string arr[], int n)
    {
        unordered_map<string, int> strCount;
        int maxCount = 0;
        for (int i = 0; i < n; i++)
        {
            strCount[arr[i]]++;
            maxCount = max(maxCount, strCount[arr[i]]);
        }
        int secMaxCount = 0;
        string secMax;
        for (auto it : strCount)
        {
            if (it.second != maxCount && it.second > secMaxCount)
            {
                secMaxCount = it.second;
                secMax = it.first;
            }
        }
        return secMax;
    }
};

int main()
{

    return 0;
}