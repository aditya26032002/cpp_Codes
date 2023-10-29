#include <bits/stdc++.h>
using namespace std;

long long int getPower(int a, int b)
{
    if (a < 0)
        return -1;
    if (b == 0)
        return 1;

    long long int val = getPower(a, b / 2);
    if (b & 1)
        return val * val * a;
    else
        return val * val;
}

// all are small alphabets
bool match(string text, string pattern)
{
    int patLen = pattern.length(), textLen = text.length();
    long long int patHash = 0, windowHash = 0;
    int power = patLen - 1;
    for (int i = 0; i < patLen; i++)
    {
        long long int ascii = pattern[i] - 'a' + 1;
        long long int toPower = getPower(26, power--);
        patHash += (ascii * toPower);
    }
    // cout << patHash << endl;
    power = patLen - 1;
    int i = 0;
    for (; i < patLen; i++)
    {
        windowHash += (text[i] - 'a' + 1) * getPower(26, power--);
    }
    // cout << windowHash << endl;
    if (windowHash == patHash)
        return true;
    for (; i < textLen; i++)
    {
        windowHash -= (text[i - patLen] - 'a' + 1) * getPower(26, patLen - 1);
        windowHash = (text[i] - 'a' + 1) + windowHash * 26;
        // cout << windowHash << endl;
        if (windowHash == patHash)
            return true;
    }
    return false;
}

int main()
{
    string pattern = "aaba", text = "aaaaaaba";
    cout << match(text, pattern);
    return 0;
}