#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solveRecursively(string &s, int index, string tempAns, int dotsRem, vector<string> &ips)
    {
        if (dotsRem == 0)
        {
            string nxt = s.substr(index, s.length() - index);
            if (nxt.length() > 3 || (nxt.length() > 1 && nxt[0] == '0'))
                return;

            if (stoi(nxt) > 255)
                return;

            tempAns += nxt;
            ips.push_back(tempAns);
            return;
        }

        string temp = "";
        for (; s.length() - index > 1; index++)
        {
            temp.push_back(s[index]);
            if (stoi(temp) > 255)
                return;

            tempAns.push_back(s[index]);
            solveRecursively(s, index + 1, tempAns + '.', dotsRem - 1, ips);

            if (temp.length() == 1 && temp[0] == '0')
                return;
        }
    }

    vector<string> genIp(string &s)
    {
        vector<string> ips;
        if (s.length() < 4)
        {
            ips.push_back("-1");
            return ips;
        }
        solveRecursively(s, 0, "", 3, ips);
        if (ips.size() == 0)
        {
            ips.push_back("-1");
            return ips;
        }
        sort(ips.begin(), ips.end());
        return ips;
    }
};

int main()
{

    return 0;
}