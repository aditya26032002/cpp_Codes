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
    pair<int, int> solve(Node *root)
    {
        if (root == NULL)
            return {0, 0};

        pair<int, int> lf = solve(root->left);
        pair<int, int> rt = solve(root->right);

        pair<int, int> toRet;
        toRet.first = max(lf.first, lf.second) + max(rt.first, rt.second);
        toRet.second = lf.first + rt.first + root->data;
        return toRet;
    }
    int getMaxSum(Node *root)
    {
        // Add your code here
        pair<int, int> ans = solve(root);
        return max(ans.first, ans.second);
    }
};

int main()
{

    return 0;
}