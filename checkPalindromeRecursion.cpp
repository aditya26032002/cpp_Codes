#include <bits/stdc++.h>
using namespace std;

int checkPalindrome(string input, int s, int e)
{
    if (s >= e)
        return 1;
    if (input[s] == input[e])
        return checkPalindrome(input, s + 1, e - 1);
    else
        return 0;
}

int main()
{
    string input = "abcdba";
    cout << checkPalindrome(input, 0, input.size() - 1);
    return 0;
}