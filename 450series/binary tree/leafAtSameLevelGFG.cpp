#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

class Solution
{
public:
    /*You are required to complete this method*/
    bool checkLeaf(Node *root, int h, int &maxH)
    {
        if (root == NULL)
            return true;

        if (root->left == NULL && root->right == NULL)
        {
            if (h != maxH)
                return false;
            return true;
        }

        bool l = checkLeaf(root->left, h + 1, maxH);
        bool r = checkLeaf(root->right, h + 1, maxH);
        return l && r;
    }
    int getHeight(Node *root)
    {
        if (root == NULL)
            return 0;

        int lh = getHeight(root->left);
        int rh = getHeight(root->right);

        return max(lh, rh) + 1;
    }
    bool check(Node *root)
    {
        int height = getHeight(root);
        return checkLeaf(root, 1, height);
    }
};

int main()
{

    return 0;
}