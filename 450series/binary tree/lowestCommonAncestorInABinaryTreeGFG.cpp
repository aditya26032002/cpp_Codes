#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

class Solution
{
public:
    // Function to return the lowest common ancestor in a Binary Tree.
    Node *lca(Node *root, int n1, int n2)
    {
        if (root == NULL)
            return NULL;

        if (root->data == n1 || root->data == n2)
            return root;

        Node *lf = lca(root->left, n1, n2);
        Node *rt = lca(root->right, n1, n2);
        if (lf != NULL && rt != NULL)
            return root;
        if (lf != NULL)
            return lf;
        if (rt != NULL)
            return rt;
        return NULL;
    }
};

int main()
{

    return 0;
}