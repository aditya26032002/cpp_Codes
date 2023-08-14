#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

class Solution
{
public:
    // Time: O(n), Space: O(1) using morris traversal
    void flatten(Node *root)
    {
        Node *curr = root;
        while (curr != NULL)
        {
            if (curr->left)
            {
                Node *pred = curr->left;
                while (pred->right != NULL)
                {
                    pred = pred->right;
                }
                pred->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
            curr = curr->right;
        }
    }

    /*
    // Time: O(n), Space: O(n) using recursion
    Node *solve(Node *curr)
    {
        if (curr == NULL)
            return NULL;
        if (curr->left == NULL && curr->right == NULL)
        {
            return curr;
        }

        Node *lastOfLeft = NULL;
        Node *lastOfRight = NULL;

        if (curr->left != NULL)
        {
            lastOfLeft = solve(curr->left);
        }
        if (curr->right != NULL)
        {
            lastOfRight = solve(curr->right);

            if (lastOfLeft)
            {
                lastOfLeft->right = curr->right;
                curr->right = NULL;
            }
            return lastOfRight;
        }
        return lastOfLeft;
    }

    void flatten(Node *root)
    {
        Node *temp = solve(root);
        temp = root;
        while (temp != NULL)
        {
            if (temp->left)
            {
                temp->right = temp->left;
                temp->left = NULL;
            }
            temp = temp->right;
        }
    }
     */
};

int main()
{

    return 0;
}