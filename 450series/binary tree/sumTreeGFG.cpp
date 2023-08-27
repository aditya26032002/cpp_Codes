#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

// Should return true if tree is Sum Tree, else false
class Solution
{
public:
    int sum(Node *root, bool &ans)
    {
        if (root == NULL)
            return 0;

        if (root->left == NULL && root->right == NULL)
        {
            return root->data;
        }

        int l = sum(root->left, ans);
        int r = sum(root->right, ans);

        if (root->data != l + r)
            ans = false;

        return l + r + root->data;
    }
    bool isSumTree(Node *root)
    {
        bool ans = true;
        int t = sum(root, ans);
        return ans;
    }
};

int main()
{

    return 0;
}