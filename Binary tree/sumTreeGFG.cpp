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
    int getSum(Node *node, bool &ans)
    {
        if (node == NULL)
        {
            return 0;
        }
        if (node->left == NULL && node->right == NULL)
        {
            return node->data;
        }

        int lfSum = getSum(node->left, ans);
        int rghtSum = getSum(node->right, ans);

        if (node->data != (lfSum + rghtSum))
        {
            ans = false;
        }
        return lfSum + rghtSum + node->data;
    }

    bool isSumTree(Node *root)
    {
        bool ans = true;
        int sum = getSum(root, ans);
        return ans;
    }
};

int main()
{

    return 0;
}