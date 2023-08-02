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
    // Function to return the diameter of a Binary Tree.

    int solve(Node *node, int &ans)
    {
        if (node == NULL)
        {
            return 0;
        }

        int leftHeight = solve(node->left, ans);
        int rightHeight = solve(node->right, ans);

        int currDiameter = leftHeight + rightHeight + 1;

        ans = max(ans, currDiameter);
        return max(leftHeight, rightHeight) + 1;
    }
    int diameter(Node *root)
    {
        // Your code here
        int ans = 0;
        int height = solve(root, ans);
        return ans;
    }
};

int main()
{

    return 0;
}