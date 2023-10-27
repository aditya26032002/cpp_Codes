#include <bits/stdc++.h>
using namespace std;

bool checkValidShuffle(string s1, string s2, string s3)
{
    if (s1.length() + s2.length() != s3.length())
        return false;

    int count[26] = {0};
    for (int i = 0; i < s1.length(); i++)
    {
        count[s1[i] - 'a']++;
    }
    for (int i = 0; i < s2.length(); i++)
        count[s2[i] - 'a']++;

    int counts3[26] = {0};
    for (int i = 0; i < s3.length(); i++)
        counts3[s3[i] - 'a']++;

    for (int i = 0; i < 26; i++)
    {
        if (count[i] != counts3[i])
            return false;
    }
    return true;
}

int main()
{
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    cout << checkValidShuffle(s1, s2, s3);
    return 0;
}