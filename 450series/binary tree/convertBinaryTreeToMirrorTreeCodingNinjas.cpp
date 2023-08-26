#include <bits/stdc++.h>
using namespace std;

template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

void solve(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;

    BinaryTreeNode<int> *lft = root->left;
    BinaryTreeNode<int> *rght = root->right;
    root->left = rght;
    root->right = lft;
    solve(lft);
    solve(rght);
}

void mirrorTree(BinaryTreeNode<int> *root)
{
    // Write your code here.
    solve(root);
}

int main()
{

    return 0;
}