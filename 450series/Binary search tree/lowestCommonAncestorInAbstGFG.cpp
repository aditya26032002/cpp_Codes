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
    Node *LCA(Node *root, int n1, int n2)
    {
        if (root == NULL)
            return NULL;

        if (root->data == n1 || root->data == n2)
            return root;

        Node *l = LCA(root->left, n1, n2);
        Node *r = LCA(root->right, n1, n2);

        if (l != NULL && r != NULL)
            return root;
        if (l != NULL)
            return l;
        else
            return r;
    }
};

int main()
{

    return 0;
}