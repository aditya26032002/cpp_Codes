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
    TreeNode *solve(vector<int> &preorder, vector<int> &inorder, int inSt, int inEn, int pre)
    {
        if (inSt > inEn)
            return NULL;

        int index = inSt;
        while (inorder[index] != preorder[pre])
        {
            index++;
        }
        int countLeft = index - inSt;
        TreeNode *root = new TreeNode(inorder[index]);

        root->left = solve(preorder, inorder, inSt, index - 1, pre + 1);
        root->right = solve(preorder, inorder, index + 1, inEn, pre + countLeft + 1);

        return root;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int st = 0;
        int en = preorder.size() - 1;
        return solve(preorder, inorder, st, en, st);
    }
};

int main()
{

    return 0;
}