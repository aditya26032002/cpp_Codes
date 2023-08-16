#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
};

TreeNode *getMin(TreeNode *root)
{
    if (root == NULL)
        return NULL;

    TreeNode *ptr = root;
    while (ptr->left != NULL)
        ptr = ptr->left;
    return ptr;
}

TreeNode *getMax(TreeNode *root)
{
    if (root == NULL)
        return NULL;

    TreeNode *ptr = root;
    while (ptr->right != NULL)
        ptr = ptr->right;
    return ptr;
}

TreeNode *successor(TreeNode *root, TreeNode *keyNode)
{
    if (keyNode->right != NULL)
        return getMin(keyNode->right);

    TreeNode *succ = NULL;
    TreeNode *ptr = root;
    while (ptr != keyNode)
    {
        if (ptr->data > keyNode->data)
        {
            succ = ptr;
            ptr = ptr->left;
        }
        else
            ptr = ptr->right;
    }
    if (ptr != NULL)
        return succ;

    return NULL;
}

pair<int, int> ifKeyNotInTree(TreeNode *root, int key)
{
    pair<int, int> predSucc = make_pair(-1, -1);
    TreeNode *ptr = root;
    while (ptr != NULL)
    {
        if (key < ptr->data)
            ptr = ptr->left;
        else
        {
            predSucc.first = ptr->data;
            ptr = ptr->right;
        }
    }

    ptr = root;
    while (ptr != NULL)
    {
        if (key > ptr->data)
            ptr = ptr->right;
        else
        {
            predSucc.second = ptr->data;
            ptr = ptr->left;
        }
    }

    return predSucc;
}

pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
    TreeNode *pred = NULL, *suc = NULL;

    pair<int, int> ans = make_pair(-1, -1);

    TreeNode *ptr = root;
    while (ptr != NULL && ptr->data != key)
    {
        if (key < ptr->data)
            ptr = ptr->left;
        else
            ptr = ptr->right;
    }

    if (ptr != NULL)
    {
        pred = getMax(ptr->left);
        suc = successor(root, ptr);
    }
    else
        return ifKeyNotInTree(root, key);

    if (pred)
        ans.first = pred->data;

    if (suc)
        ans.second = suc->data;

    return ans;
}

int main()
{

    return 0;
}