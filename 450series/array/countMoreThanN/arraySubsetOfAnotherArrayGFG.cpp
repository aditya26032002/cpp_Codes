#include <bits/stdc++.h>
using namespace std;

string isSubset(int a1[], int a2[], int n, int m)
{
    if (m > n)
        return "No";
    unordered_map<int, int> occCount;
    for (int i = 0; i < m; i++)
    {
        occCount[a2[i]]++;
    }
    for (int i = 0; i < n; i++)
    {
        occCount[a1[i]]--;
    }
    for (auto it : occCount)
    {
        if (it.second > 0)
            return "No";
    }
    return "Yes";
}

int main()
{

    return 0;
}