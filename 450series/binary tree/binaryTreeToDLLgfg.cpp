#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

// This function should return head to the DLL
class Solution
{
public:
    // Function to convert binary tree to doubly linked list and return it.

    pair<Node *, Node *> solve(Node *root)
    {
        if (root == NULL)
            return {NULL, NULL};

        pair<Node *, Node *> range;
        pair<Node *, Node *> lf = solve(root->left);
        pair<Node *, Node *> rt = solve(root->right);

        root->left = NULL;
        root->right = NULL;

        if (lf.first != NULL)
        {
            range.first = lf.first;
            lf.second->right = root;
            root->left = lf.second;
        }
        else
        {
            range.first = root;
        }

        if (rt.second != NULL)
        {
            range.second = rt.second;
            root->right = rt.first;
            rt.first->left = root;
        }
        else
        {
            range.second = root;
        }
        return range;
    }

    Node *bToDLL(Node *root)
    {
        // your code here
        return solve(root).first;
    }
};

int main()
{

    return 0;
}