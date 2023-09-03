#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        key = x;
        left = NULL;
        right = NULL;
    }
};

// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
class Solution
{
public:
    void findPreSuc(Node *root, Node *&pre, Node *&suc, int key)
    {
        Node *ptr = root;
        while (ptr != NULL)
        {
            if (ptr->key == key)
            {
                break;
            }
            if (ptr->key > key)
            {
                suc = ptr;
                ptr = ptr->left;
            }
            else
            {
                pre = ptr;
                ptr = ptr->right;
            }
        }
        if (ptr != NULL)
        {
            if (ptr->left != NULL)
            {
                pre = ptr->left;
                while (pre->right != NULL)
                    pre = pre->right;
            }
            if (ptr->right != NULL)
            {
                suc = ptr->right;
                while (suc->left != NULL)
                    suc = suc->left;
            }
        }
    }
};

int main()
{

    return 0;
}