#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

// Your are required to complete this function
// function should return root of the modified BST

void inorder(Node *root, vector<Node *> &v)
{
    if (root == NULL)
        return;

    inorder(root->left, v);
    v.push_back(root);
    inorder(root->right, v);
}

Node *alterBST(vector<Node *> &v, int s, int e)
{
    if (s > e)
        return NULL;

    int mid = s + (e - s) / 2;

    v[mid]->left = alterBST(v, s, mid - 1);
    v[mid]->right = alterBST(v, mid + 1, e);
    return v[mid];
}

Node *buildBalancedTree(Node *root)
{
    vector<Node *> v;
    inorder(root, v);
    return alterBST(v, 0, v.size() - 1);
}

int main()
{

    return 0;
}