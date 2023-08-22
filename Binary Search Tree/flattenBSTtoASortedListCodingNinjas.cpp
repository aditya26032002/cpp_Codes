#include <bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;
};

/*
pair<TreeNode<int> *, TreeNode<int> *> solve(TreeNode<int> *root)
{
    if (root == NULL)
        return {NULL, NULL};

    if (root->left == NULL && root->right == NULL)
        return {root, root};

    pair<TreeNode<int> *, TreeNode<int> *> toRet;
    pair<TreeNode<int> *, TreeNode<int> *> lft = solve(root->left);
    pair<TreeNode<int> *, TreeNode<int> *> rght = solve(root->right);
    root->left = NULL;
    root->right = rght.first;
    if (lft.second != NULL)
    {
        lft.second->right = root;
        toRet.first = lft.first;
    }
    else
        toRet.first = root;

    if (rght.second != NULL)
        toRet.second = rght.second;
    else
        toRet.second = root;
    return toRet;
}

TreeNode<int> *flatten(TreeNode<int> *root)
{
    pair<TreeNode<int> *, TreeNode<int> *> ans = solve(root);
    return ans.first;
}
*/

/*
void inorderTraverse(TreeNode<int> *root, vector<TreeNode<int> *> &v)
{
    if (root == NULL)
        return;
    inorderTraverse(root->left, v);
    v.push_back(root);
    inorderTraverse(root->right, v);
}

TreeNode<int> *flatten(TreeNode<int> *root)
{
    if (root == NULL)
        return NULL;
    vector<TreeNode<int> *> v;
    inorderTraverse(root, v);

    int size = v.size();
    v.push_back(NULL);
    for (int i = 0; i < size; i++)
    {
        v[i]->left = NULL;
        v[i]->right = v[i + 1];
    }
    return v[0];
}
*/

int main()
{
    return 0;
}