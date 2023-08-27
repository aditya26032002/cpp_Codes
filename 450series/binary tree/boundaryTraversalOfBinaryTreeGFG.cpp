#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

class Solution
{
public:
    void traverseLeft(Node *root, vector<int> &v)
    {
        if (root == NULL || (root->left == NULL && root->right == NULL))
            return;

        v.push_back(root->data);

        if (root->left != NULL)
            traverseLeft(root->left, v);
        else
            traverseLeft(root->right, v);
    }
    void traverseRight(Node *root, vector<int> &v)
    {
        if (root == NULL || (root->left == NULL && root->right == NULL))
            return;

        if (root->right != NULL)
            traverseRight(root->right, v);
        else
            traverseRight(root->left, v);

        v.push_back(root->data);
    }
    void traverseLeafNodes(Node *root, vector<int> &v)
    {
        if (root == NULL)
            return;
        if (root->left == NULL && root->right == NULL)
        {
            v.push_back(root->data);
            return;
        }
        traverseLeafNodes(root->left, v);
        traverseLeafNodes(root->right, v);
    }

    vector<int> boundary(Node *root)
    {
        vector<int> ans;
        if (root == NULL)
            return ans;

        ans.push_back(root->data);
        traverseLeft(root->left, ans);
        traverseLeafNodes(root->left, ans);
        traverseLeafNodes(root->right, ans);
        traverseRight(root->right, ans);
        return ans;
    }
};

int main()
{

    return 0;
}