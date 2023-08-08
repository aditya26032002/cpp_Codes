#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
};
// your task is to complete this function

bool solve(Node *curr, int &k, int &node, int &ans)
{
    if (curr == NULL)
    {
        return false;
    }

    if (curr->data == node)
    {
        return true;
    }

    bool findLeft = solve(curr->left, k, node, ans);
    bool findRight = solve(curr->right, k, node, ans);

    if (findLeft || findRight)
    {
        k--;
        if (k == 0)
        {
            k = -1;
            ans = curr->data;
        }
    }

    return (findLeft || findRight);
}

int kthAncestor(Node *root, int k, int node)
{
    int ans = -1;
    bool temp = solve(root, k, node, ans);
    return ans;
}

int main()
{

    return 0;
}