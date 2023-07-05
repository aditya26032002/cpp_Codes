#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to delete middle element of a stack.
    void solution(stack<int> &s, int k)
    {
        if (k == 0)
        {
            s.pop();
            return;
        }
        int temp = s.top();
        s.pop();
        solution(s, k - 1);
        s.push(temp);
    }
    void deleteMid(stack<int> &s, int sizeOfStack)
    {
        solution(s, (sizeOfStack / 2));
    }
};

int main()
{

    return 0;
}