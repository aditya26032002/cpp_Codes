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
    /*
    void solve(TreeNode *root, vector<int> &v)
    {
        if (root == NULL)
            return;
        v.push_back(root->val);
        solve(root->left, v);
        solve(root->right, v);
    }
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> v;
        solve(root, v);
        return v;
    }
    */
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> v;
        while (root != NULL)
        {
            if (root->left == NULL)
            {
                v.push_back(root->val);
                root = root->right;
            }

            else
            {
                TreeNode *pred = root->left;
                while (pred->right != NULL && pred->right != root)
                    pred = pred->right;
                if (pred->right == NULL)
                {
                    pred->right = root;
                    v.push_back(root->val);
                    root = root->left;
                }
                else
                {
                    pred->right = NULL;
                    root = root->right;
                }
            }
        }
        return v;
    }
};

int main()
{

    return 0;
}