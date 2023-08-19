#include <bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

// Time: O(n) Space: O(n)
TreeNode<int> *buildTree(vector<int> &inorder, int s, int e)
{
    if (s > e)
        return NULL;

    int index = s + (e - s + 1) / 2;
    TreeNode<int> *curr = new TreeNode<int>(inorder[index]);
    curr->left = buildTree(inorder, s, index - 1);
    curr->right = buildTree(inorder, index + 1, e);
    return curr;
}

void inorderTraverse(TreeNode<int> *root, vector<int> &inorder)
{
    if (root == NULL)
        return;

    inorderTraverse(root->left, inorder);
    inorder.push_back(root->data);
    inorderTraverse(root->right, inorder);
}

TreeNode<int> *balancedBst(TreeNode<int> *root)
{
    // Write your code here.
    vector<int> inorder;
    inorderTraverse(root, inorder);
    root = buildTree(inorder, 0, inorder.size() - 1);
    return root;
}

int main()
{

    return 0;
}