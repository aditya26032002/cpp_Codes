#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string FirstNonRepeating(string A)
    {
        string ans = "";
        int alphabets[26] = {0};
        queue<char> q;
        for (int i = 0; i < A.length(); i++)
        {
            int index = A[i] - 'a';
            alphabets[index]++;

            if (alphabets[index] == 1)
                q.push(A[i]);

            while (!q.empty() && alphabets[q.front() - 'a'] > 1)
                q.pop();

            if (q.empty())
                ans += '#';
            else
                ans += q.front();
        }
        return ans;
    }
};

int main()
{

    return 0;
}