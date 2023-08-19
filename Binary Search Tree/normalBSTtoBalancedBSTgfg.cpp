#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

Node *buildTree(vector<Node *> &inorder, int s, int e)
{
    if (s > e)
        return NULL;

    int index = s + (e - s + 1) / 2;
    inorder[index]->left = buildTree(inorder, s, index - 1);
    inorder[index]->right = buildTree(inorder, index + 1, e);
    return inorder[index];
}

void inorderTraverse(Node *root, vector<Node *> &inorder)
{
    if (root == NULL)
        return;

    inorderTraverse(root->left, inorder);
    inorder.push_back(root);
    inorderTraverse(root->right, inorder);
}

Node *buildBalancedTree(Node *root)
{
    vector<Node *> inorder;
    inorderTraverse(root, inorder);
    root = buildTree(inorder, 0, inorder.size() - 1);
    return root;
}

/* // Leetcode
class Solution {
public:

    TreeNode* buildTree(vector<TreeNode*> &inorder, int s, int e)
    {
        if(s>e)
            return NULL;

        int index = s + (e-s+1)/2;
        inorder[index]->left = buildTree(inorder, s, index-1);
        inorder[index]->right = buildTree(inorder, index+1, e);
        return inorder[index];
    }

    void inorderTraverse(TreeNode* root, vector<TreeNode*> &inorder)
    {
        if(root == NULL)
            return;

        inorderTraverse(root->left, inorder);
        inorder.push_back(root);
        inorderTraverse(root->right, inorder);
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*> inorder;
        inorderTraverse(root, inorder);
        root = buildTree(inorder, 0, inorder.size()-1);
        return root;
    }
};
*/

int main()
{

    return 0;
}