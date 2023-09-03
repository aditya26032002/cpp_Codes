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
    // Function to check whether a Binary Tree is BST or not.
    bool validateRange(Node *root, int min, int max)
    {
        if (root == NULL)
            return true;

        if (!(root->data > min && root->data < max))
            return false;

        return validateRange(root->left, min, root->data) && validateRange(root->right, root->data, max);
    }

    bool isBST(Node *root)
    {
        return validateRange(root, INT_MIN, INT_MAX);
    }
};

int main()
{

    return 0;
}