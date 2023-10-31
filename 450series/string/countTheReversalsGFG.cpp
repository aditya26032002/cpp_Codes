#include <bits/stdc++.h>
using namespace std;

int countRev(string s)
{
    int openings = 0;
    int count = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '{')
            openings++;
        else
        {
            if (openings == 0)
            {
                openings++;
                count++;
            }
            else
                openings--;
        }
    }
    if (openings & 1)
        return -1;
    count += (openings / 2);
    return count;
}

int main()
{

    return 0;
}