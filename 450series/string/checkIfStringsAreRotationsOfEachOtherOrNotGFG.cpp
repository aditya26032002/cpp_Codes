#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Time : O(n)  Space : O(n)
    bool areRotations(string s1, string s2)
    {
        if (s1.length() != s2.length())
            return false;
        if (s1 == s2)
            return true;
        string temp = s1 + s1;
        if (temp.find(s2) != string::npos)
            return true;
        return false;
    }
};

int main()
{

    return 0;
}