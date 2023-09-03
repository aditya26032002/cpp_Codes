#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

int minValue(Node *root)
{
    if (root == NULL)
        return -1;
    while (root->left != NULL)
        root = root->left;
    return root->data;
}

int main()
{

    return 0;
}