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
    // Function to return the maximum sum of non-adjacent nodes.

    pair<int, int> findMaxSum(Node *curr)
    {
        if (curr == NULL)
        {
            return make_pair(0, 0);
        }

        pair<int, int> ans;
        pair<int, int> leftAns = findMaxSum(curr->left);
        pair<int, int> rightAns = findMaxSum(curr->right);

        ans.first = leftAns.second + rightAns.second + curr->data;
        ans.second = max(leftAns.first, leftAns.second) + max(rightAns.first, rightAns.second);

        return ans;
    }

    int getMaxSum(Node *root)
    {
        pair<int, int> ans = findMaxSum(root);
        return max(ans.first, ans.second);
    }
};

int main()
{

    return 0;
}