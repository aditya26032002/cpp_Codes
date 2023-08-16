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
    // returns the inorder successor of the Node x in BST (rooted at 'root')

    Node *getMin(Node *root)
    {
        Node *curr = root;
        while (curr->left != NULL)
            curr = curr->left;
        return curr;
    }

    Node *inOrderSuccessor(Node *root, Node *x)
    {
        if (x->right != NULL)
            return getMin(x->right);

        Node *succ = NULL;
        Node *temp = root;
        while (temp != x)
        {
            if (temp->data > x->data)
            {
                succ = temp;
                temp = temp->left;
            }
            else
                temp = temp->right;
        }
        if (temp)
            return succ;
        return succ;
    }
};

int main()
{

    return 0;
}