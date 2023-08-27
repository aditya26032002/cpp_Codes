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
    void solve(TreeNode *root, string &st)
    {
        if (root == NULL)
            return;
        string stri = to_string(root->val);
        st += stri;
        if (root->left == NULL && root->right == NULL)
            return;
        st += '(';
        solve(root->left, st);
        st += ')';
        if (root->right != NULL)
        {
            st += '(';
            solve(root->right, st);
            st += ')';
        }
    }
    string tree2str(TreeNode *root)
    {
        string ans = "";
        solve(root, ans);
        return ans;
    }
};

int main()
{

    return 0;
}