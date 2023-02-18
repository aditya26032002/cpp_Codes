#include <bits/stdc++.h>
using namespace std;

bool checkPalindrome(string input, int st, int en)
{
    for (; st <= en; st++, en--)
    {
        if (input[st] != input[en])
            return false;
    }
    return true;
}

int numOfPartitioning(string input)
{
    int size = input.size();
    int ans = size - 1;
    int st = 0, sizeOfPalindromeString = 2;
    while (sizeOfPalindromeString < size)
    {
        int st = 0;
        int numOfPalindromes = 0;
        int partitions = 0;
        int prevPalindromeAt = size;
        while ((st + sizeOfPalindromeString - 1) < size)
        {
            if (checkPalindrome(input, st, (st + sizeOfPalindromeString - 1)))
            {
                if (partitions == 0)
                    partitions++;
                if (st - sizeOfPalindromeString > prevPalindromeAt)
                    partitions++;
                if (st == 0 && (st + sizeOfPalindromeString - 1) == size - 1)
                {
                    break;
                }
                else if (st == 0 && (st + sizeOfPalindromeString - 1) != size - 1)
                {
                    partitions++;
                }
                else if (st != 0 && (st + sizeOfPalindromeString - 1) == size - 1)
                {
                }
                else if (st != 0 && (st + sizeOfPalindromeString - 1) != size - 1)
                {
                    partitions++;
                }
                st += sizeOfPalindromeString;
                prevPalindromeAt = st;
            }
            else
                st++;
        }
        // cout << partitions << endl;
        if (partitions && partitions < ans)
            ans = partitions;

        sizeOfPalindromeString++;
    }
    return ans;
}

int main()
{
    string input = "staabble";
    // string input = "aab";
    // string input = "staazbble";
    // string input;
    // cout << "Input string : ";
    // cin >> input;
    cout << numOfPartitioning(input);
    return 0;
}