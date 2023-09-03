#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

bool search(Node *root, int x)
{
    while (root != NULL)
    {
        if (root->data == x)
            return true;
        if (root->data > x)
            root = root->left;
        else
            root = root->right;
    }
    return false;
}

int main()
{

    return 0;
}