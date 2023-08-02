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

    /*
    void getHeight(struct Node *node, int &ans, int currHeight)
    {
        if (node == NULL)
        {
            ans = max(ans, currHeight);
            return;
        }
        getHeight(node->left, ans, currHeight + 1);
        getHeight(node->right, ans, currHeight + 1);
    }

    int height(struct Node *node)
    {
        // code here
        int ans = 0;
        getHeight(node, ans, 0);
        return ans;
    }
    */

    int height(struct Node *node)
    {
        if (node == NULL)
        {
            return 0;
        }

        int leftHeight = height(node->left);
        int rightHeight = height(node->right);

        return max(leftHeight, rightHeight) + 1;
    }
};

int main()
{

    return 0;
}