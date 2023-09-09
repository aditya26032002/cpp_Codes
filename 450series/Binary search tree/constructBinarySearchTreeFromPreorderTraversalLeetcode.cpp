#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    // Time: O(n) space: O(1)
    TreeNode *solve(vector<int> &preorder, int lft, int rght, int &i)
    {
        if (i >= preorder.size())
            return NULL;

        TreeNode *root = NULL;
        if (preorder[i] > lft && preorder[i] < rght)
        {
            root = new TreeNode(preorder[i++]);
            root->left = solve(preorder, lft, root->val, i);
            root->right = solve(preorder, root->val, rght, i);
            return root;
        }
        else
            return NULL;
    }

    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        int i = 0;
        TreeNode *root = solve(preorder, INT_MIN, INT_MAX, i);
        return root;
    }
    /* Time: O(n^2) space: O(1)
    TreeNode *build(vector<int> &preorder, int s, int e)
    {
        if (s > e)
            return NULL;

        TreeNode *node = new TreeNode(preorder[s]);

        int index = s + 1;
        while (index <= e && preorder[index] < preorder[s])
            index++;

        node->left = build(preorder, s + 1, index - 1);
        node->right = build(preorder, index, e);
        return node;
    }
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        int s = 0, e = preorder.size() - 1;
        return build(preorder, s, e);
    }
    */
};

int main()
{

    return 0;
}