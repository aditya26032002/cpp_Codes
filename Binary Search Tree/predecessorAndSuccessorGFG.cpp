#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
};

// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
class Solution
{
public:
    void successor(Node *root, int &data, Node *&succ)
    {
        if (root == NULL)
            return;

        if (data < root->key)
        {
            succ = root;
            return successor(root->left, data, succ);
        }
        else
            return successor(root->right, data, succ);
    }

    void predecessor(Node *root, int &data, Node *&pred)
    {
        if (root == NULL)
            return;

        if (data > root->key)
        {
            pred = root;
            return predecessor(root->right, data, pred);
        }
        else
            return predecessor(root->left, data, pred);
    }

    void findPreSuc(Node *root, Node *&pre, Node *&suc, int key)
    {
        pre = NULL;
        suc = NULL;
        successor(root, key, suc);
        predecessor(root, key, pre);
    }
};

int main()
{

    return 0;
}