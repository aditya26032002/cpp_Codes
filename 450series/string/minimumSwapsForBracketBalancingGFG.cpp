#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumNumberOfSwaps(string S)
    {
        int openings = 0, swaps = 0;
        int nextOpenBracket = 0;
        for (int i = 0; i < S.length(); i++)
        {
            if (S[i] == ']')
            {
                if (openings > 0)
                    openings--;
                else
                {
                    nextOpenBracket = i + 1;

                    while (S[nextOpenBracket] != '[')
                        nextOpenBracket++;

                    swap(S[i], S[nextOpenBracket]);
                    swaps += (nextOpenBracket - i);
                    openings++;
                }
            }
            else
                openings++;
        }
        return swaps;
    }
};

int main()
{

    return 0;
}