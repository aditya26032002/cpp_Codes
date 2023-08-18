#include <bits/stdc++.h>
using namespace std;

template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;
};

// Space: O(1) Time: O(n)
/*
We will traverse whole tree using morris traversal,
because if we return the ans as soon as we found it,
there may remain changes in the original tree which left unchanged.
However, in GFG and Coding Ninjas, it is accepted but not in Leetcode.
*/
int kthSmallest(BinaryTreeNode<int> *root, int k)
{
    int ans = -1;
    BinaryTreeNode<int> *curr = root;
    while (curr != NULL)
    {
        if (curr->left == NULL)
        {
            if (k == 1)
                ans = curr->data;
            curr = curr->right;
            k--;
        }
        else
        {
            BinaryTreeNode<int> *ptr = curr->left;

            while (ptr->right != NULL && ptr->right != curr)
                ptr = ptr->right;

            if (ptr->right == NULL)
            {
                ptr->right = curr;
                curr = curr->left;
            }
            else
            {
                ptr->right = NULL;
                if (k == 1)
                    ans = curr->data;
                curr = curr->right;
                k--;
            }
        }
    }
    return ans;
}

/* // Space: O(n) Time: O(n)
void inorderTraversal(BinaryTreeNode<int> *root, vector<int> &inorder)
{
    if (root == NULL)
        return;

    inorderTraversal(root->left, inorder);
    inorder.push_back(root->data);
    inorderTraversal(root->right, inorder);
}

int kthSmallest(BinaryTreeNode<int> *root, int k)
{
    vector<int> inorder;
    inorderTraversal(root, inorder);
    if (k - 1 < inorder.size())
        return inorder[k - 1];
    return -1;
}
*/

int main()
{

    return 0;
}