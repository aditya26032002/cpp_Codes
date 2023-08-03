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
    // Function to check whether a binary tree is balanced or not.
    int getHeight(Node *node, bool &ans)
    {
        if (node == NULL)
        {
            return 0;
        }
        int leftHeight = getHeight(node->left, ans);
        int rightHeight = getHeight(node->right, ans);

        if (abs(leftHeight - rightHeight) > 1)
        {
            ans = false;
        }
        return max(leftHeight, rightHeight) + 1;
    }

    bool isBalanced(Node *root)
    {
        bool ans = true;
        int tmp = getHeight(root, ans);
        return ans;
    }
};

int main()
{

    return 0;
}