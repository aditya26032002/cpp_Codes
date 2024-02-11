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
    // Function to return a list of integers denoting the node
    // values of both the BST in a sorted order.
    pair<Node *, Node *> flatten(Node *root)
    {
        if (root == NULL)
            return {NULL, NULL};

        Node *leftNode = NULL;
        Node *rightNode = NULL;

        pair<Node *, Node *> lft = flatten(root->left);
        pair<Node *, Node *> rght = flatten(root->right);

        root->left = NULL;
        root->right = rght.first;
        if (lft.first != NULL)
        {
            lft.second->right = root;
            leftNode = lft.first;
        }
        else
            leftNode = root;

        if (rght.second != NULL)
            rightNode = rght.second;
        else
            rightNode = root;

        return {leftNode, rightNode};
    }

    vector<int> merge(Node *root1, Node *root2)
    {
        root1 = (flatten(root1)).first;
        root2 = (flatten(root2)).first;
        vector<int> ans;

        while (root1 != NULL && root2 != NULL)
        {
            if (root1->data < root2->data)
            {
                ans.push_back(root1->data);
                root1 = root1->right;
            }
            else
            {
                ans.push_back(root2->data);
                root2 = root2->right;
            }
        }
        while (root1 != NULL)
        {
            ans.push_back(root1->data);
            root1 = root1->right;
        }
        while (root2 != NULL)
        {
            ans.push_back(root2->data);
            root2 = root2->right;
        }

        return ans;
    }
};

int main()
{

    return 0;
}