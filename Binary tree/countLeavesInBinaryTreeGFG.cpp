#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

void solve(Node *root, int &leaf)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left == NULL && root->right == NULL)
    {
        leaf++;
        return;
    }
    solve(root->left, leaf);
    solve(root->right, leaf);
}

int countLeaves(Node *root)
{
    int numOfLeaf = 0;
    solve(root, numOfLeaf);
    return numOfLeaf;
}

int main()
{

    return 0;
}