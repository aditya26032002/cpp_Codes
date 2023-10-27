#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string convertInString(string ip)
    {
        string output = "";
        for (int i = 0; i < ip.length(); i++)
        {
            int count = 1;
            while (i + 1 < ip.length() && ip[i] == ip[i + 1])
            {
                i++;
                count++;
            }
            char strCount = ('0' + count);
            output = output + strCount + ip[i];
        }
        return output;
    }
    string countAndSay(int n)
    {
        string ans = "1";
        for (int i = 2; i <= n; i++)
        {
            ans = convertInString(ans);
        }
        return ans;
    }
};

int main()
{

    return 0;
}