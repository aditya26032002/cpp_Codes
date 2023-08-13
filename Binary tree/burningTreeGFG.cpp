#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

class Solution
{
public:
    pair<bool, int> findMaxPath(Node *curr, int &target, int &ans)
    {
        if (curr == NULL)
        {
            return make_pair(false, 0);
        }

        if (curr->data == target)
        {
            pair<bool, int> leftlen = findMaxPath(curr->left, target, ans);
            pair<bool, int> rightlen = findMaxPath(curr->right, target, ans);

            int lenUnderneathCurr = max(leftlen.second, rightlen.second);
            ans = max(lenUnderneathCurr, ans);

            return make_pair(true, 0);
        }

        pair<bool, int> leftlen = findMaxPath(curr->left, target, ans);
        pair<bool, int> rightlen = findMaxPath(curr->right, target, ans);

        bool found = leftlen.first || rightlen.first;

        if (found)
        {
            int maxLen = leftlen.second + rightlen.second + 1;
            ans = max(maxLen, ans);

            if (leftlen.first)
            {
                leftlen.second++;
                return leftlen;
            }

            if (rightlen.first)
            {
                rightlen.second++;
                return rightlen;
            }
        }

        if (leftlen.second >= rightlen.second)
        {
            leftlen.second++;
            return leftlen;
        }

        rightlen.second++;
        return rightlen;
    }

    int minTime(Node *root, int target)
    {
        int ans = 0;
        pair<bool, int> temp = findMaxPath(root, target, ans);
        return ans;
    }
};

int main()
{

    return 0;
}