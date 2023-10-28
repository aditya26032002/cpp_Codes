#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSubStr(string str)
    {
        int count = 0;
        int en = 0;
        int zeros = 0, ones = 0;
        while (en < str.length())
        {
            if (str[en] == '0')
                zeros++;
            else
                ones++;
            if (zeros != 0 && zeros == ones)
            {
                count++;
                zeros = ones = 0;
            }
            en++;
        }
        if (zeros > 0 || ones > 0)
            return -1;
        return count;
    }
};

int main()
{

    return 0;
}