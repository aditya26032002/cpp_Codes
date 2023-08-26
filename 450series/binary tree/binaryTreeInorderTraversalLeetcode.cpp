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
        solve(root->left, v);
        v.push_back(root->val);
        solve(root->right, v);
    }
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> v;
        solve(root, v);
        return v;
    }
    */
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> v;
        TreeNode *ptr = root;
        while (ptr != NULL)
        {
            if (ptr->left == NULL)
            {
                v.push_back(ptr->val);
                ptr = ptr->right;
            }
            else
            {
                TreeNode *pred = ptr->left;
                while (pred->right != NULL && pred->right != ptr)
                    pred = pred->right;
                if (pred->right == ptr)
                {
                    pred->right = NULL;
                    v.push_back(ptr->val);
                    ptr = ptr->right;
                }
                else
                {
                    pred->right = ptr;
                    ptr = ptr->left;
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