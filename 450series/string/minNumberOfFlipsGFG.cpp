#include <bits/stdc++.h>
using namespace std;

int minFlips(string S)
{
    int count = 0;
    bool bit = S[0] - '0';
    for (int i = 1; i < S.length(); i++)
    {
        if ((S[i] - '0') == bit)
            count++;
        bit = !bit;
    }
    int count2 = 1;
    bit = !(S[0] - '0');
    for (int i = 1; i < S.length(); i++)
    {
        if ((S[i] - '0') == bit)
            count2++;
        bit = !bit;
    }
    return min(count, count2);
}

int main()
{

    return 0;
}