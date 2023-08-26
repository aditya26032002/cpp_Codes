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
    int getHeight(TreeNode *root, bool &ans)
    {
        if (root == NULL)
            return 0;

        int lH = getHeight(root->left, ans);
        int rH = getHeight(root->right, ans);
        if (abs(lH - rH) > 1)
            ans = false;
        return max(lH, rH) + 1;
    }

    bool isBalanced(TreeNode *root)
    {
        bool ans = true;
        int h = getHeight(root, ans);
        return ans;
    }
};

int main()
{

    return 0;
}