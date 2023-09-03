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
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (root == NULL)
            return NULL;

        if (root->val == key)
        {
            if (root->left == NULL && root->right == NULL)
                return NULL;
            if (root->left == NULL)
                return root->right;
            if (root->right == NULL)
                return root->left;

            TreeNode *leftPart = root->left;
            TreeNode *succ = root->right;
            if (succ->left == NULL)
            {
                succ->left = leftPart;
                return succ;
            }
            TreeNode *parent = NULL;
            while (succ->left != NULL)
            {
                parent = succ;
                succ = succ->left;
            }
            parent->left = succ->right;
            succ->left = leftPart;
            succ->right = root->right;
            return succ;
        }
        if (root->val > key)
            root->left = deleteNode(root->left, key);
        else
            root->right = deleteNode(root->right, key);
        return root;
    }
};

int main()
{

    return 0;
}