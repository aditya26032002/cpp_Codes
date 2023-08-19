#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
};

TreeNode *LCAinaBST(TreeNode *root, TreeNode *P, TreeNode *Q)
{
    bool foundP = false, foundQ = false;
    TreeNode *ptr = root;
    while (ptr != NULL)
    {
        if (ptr->data == P->data && ptr->data == Q->data)
            return ptr;
        if (P->data < ptr->data && Q->data < ptr->data)
            ptr = ptr->left;
        if (P->data > ptr->data && Q->data > ptr->data)
            ptr = ptr->right;
        else
            break;
    }

    if (ptr == NULL)
        return ptr;

    TreeNode *pt1 = ptr;
    while (pt1 != NULL)
    {
        if (pt1->data == P->data)
        {
            foundP = true;
            break;
        }
        if (pt1->data < P->data)
            pt1 = pt1->right;
        else
            pt1 = pt1->left;
    }
    pt1 = ptr;
    while (pt1 != NULL)
    {
        if (pt1->data == Q->data)
        {
            foundQ = true;
            break;
        }
        if (pt1->data < Q->data)
            pt1 = pt1->right;
        else
            pt1 = pt1->left;
    }

    if (foundP && foundQ)
        return ptr;
    else
        return NULL;
}

int main()
{

    return 0;
}