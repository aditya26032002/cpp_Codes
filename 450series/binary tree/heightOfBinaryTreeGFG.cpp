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

class Solution
{
public:
    // Function to find the height of a binary tree.
    int height(struct Node *node)
    {
        if (node == NULL)
            return 0;
        int leftH = height(node->left);
        int rightH = height(node->right);
        return max(leftH, rightH) + 1;
    }
};

int main()
{

    return 0;
}