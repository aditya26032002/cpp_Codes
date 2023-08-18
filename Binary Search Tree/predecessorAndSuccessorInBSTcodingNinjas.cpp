#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
};

pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
    int succ = -1;
    int pred = -1;

    TreeNode *ptr = root;
    while (ptr != NULL && ptr->data != key)
    {
        if (ptr->data > key)
        {
            succ = ptr->data;
            ptr = ptr->left;
        }
        else
        {
            pred = ptr->data;
            ptr = ptr->right;
        }
    }

    if (ptr != NULL)
    {
        if (ptr->left != NULL)
        {
            TreeNode *temp = ptr->left;
            while (temp->right != NULL)
                temp = temp->right;
            pred = temp->data;
        }
        if (ptr->right != NULL)
        {
            TreeNode *temp = ptr->right;
            while (temp->left != NULL)
                temp = temp->left;
            succ = temp->data;
        }
    }

    return make_pair(pred, succ);
}

int main()
{

    return 0;
}