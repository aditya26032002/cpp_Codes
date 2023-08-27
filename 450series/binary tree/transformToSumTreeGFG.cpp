#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

class Solution
{
public:
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree

    int solve(Node *root)
    {
        if (root == NULL)
            return 0;

        int curr = root->data;
        int lf = solve(root->left);
        int rt = solve(root->right);

        root->data = lf + rt;
        return curr + root->data;
    }

    void toSumTree(Node *node)
    {
        int x = solve(node);
    }
};

int main()
{

    return 0;
}