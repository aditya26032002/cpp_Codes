#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
};

int solve(Node *root, int &k, int &node, int &ans)
{
    if (root == NULL)
        return -1;

    if (root->data == node)
        return 1;

    int l = solve(root->left, k, node, ans);
    int r = solve(root->right, k, node, ans);

    if (l == k)
        ans = root->data;
    if (r == k)
        ans = root->data;

    if (l == -1 && r == -1)
        return -1;
    if (l != -1)
        return l + 1;
    return r + 1;
}

int kthAncestor(Node *root, int k, int node)
{
    int ans = -1;
    int t = solve(root, k, node, ans);
    return ans;
}

int main()
{

    return 0;
}