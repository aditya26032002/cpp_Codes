#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
};

bool search(Node *root, int x)
{
    if (root == NULL)
        return false;

    if (root->data == x)
        return true;

    if (x < root->data)
        return search(root->left, x);

    else
        return search(root->right, x);
}

/*
bool search(Node *root, int x)
{
    Node *ptr = root;
    while (ptr != NULL)
    {
        if (ptr->data == x)
        {
            return true;
        }
        if (ptr->data < x)
        {
            ptr = ptr->right;
        }
        else
        {
            ptr = ptr->left;
        }
    }
    return false;
}
*/

int main()
{

    return 0;
}