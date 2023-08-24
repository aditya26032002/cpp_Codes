#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

struct Node *buildTree(int &n, int pre[], char preLN[], int &i)
{
    if (i >= n)
        return NULL;

    struct Node *root = new struct Node(pre[i++]);
    if (preLN[i - 1] != 'L')
    {
        root->left = buildTree(n, pre, preLN, i);
        root->right = buildTree(n, pre, preLN, i);
    }
    return root;
}

struct Node *constructTree(int n, int pre[], char preLN[])
{
    int i = 0;
    return buildTree(n, pre, preLN, i);
}

int main()
{

    return 0;
}