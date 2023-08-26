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

    int solve(Node *root, int &ans)
    {
        if (root == NULL)
            return 0;
        int leftH = solve(root->left, ans);
        int rightH = solve(root->right, ans);
        int dia = leftH + rightH + 1;
        ans = max(ans, dia);
        return max(leftH, rightH) + 1;
    }

    int diameter(Node *root)
    {
        int ans = 0;
        int h = solve(root, ans);
        return ans;
    }
};

int main()
{

    return 0;
}