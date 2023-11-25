#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Time : O(n)  Space : O(1)
    int getDecimal(char ch)
    {
        if (ch == 'I')
            return 1;
        if (ch == 'V')
            return 5;
        if (ch == 'X')
            return 10;
        if (ch == 'L')
            return 50;
        if (ch == 'C')
            return 100;
        if (ch == 'D')
            return 500;
        if (ch == 'M')
            return 1000;
    }

    bool isSmaller(char ch1, char ch2)
    {
        int n1 = getDecimal(ch1), n2 = getDecimal(ch2);
        return n1 < n2;
    }

    int romanToDecimal(string &str)
    {
        int ans = 0;
        int size = str.length();
        int i = 0;
        while (i < size)
        {
            if (i + 1 < size && isSmaller(str[i], str[i + 1]))
            {
                ans += (getDecimal(str[i + 1]) - getDecimal(str[i]));
                i++;
            }
            else
                ans += getDecimal(str[i]);
            i++;
        }
        return ans;
    }
};

int main()
{

    return 0;
}