#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

class Solution
{
public:
    void boundaryTraversal(Node *node, bool dir, bool sameDir, vector<int> &ans)
    {
        if (node == NULL)
        {
            return;
        }
        if (node->left == NULL && node->right == NULL)
        {
            ans.push_back(node->data);
            return;
        }

        if (sameDir)
        {
            if (dir == 0) // i.e. left
            {
                if (dir ^ sameDir) // boundary element
                {
                    ans.push_back(node->data);
                }
                if (node->left != NULL)
                {
                    boundaryTraversal(node->left, 0, true, ans);
                    boundaryTraversal(node->right, 0, false, ans);
                }
                else
                {
                    boundaryTraversal(node->right, 0, true, ans);
                }
            }
            else
            {
                if (node->right != NULL)
                {
                    if (node->left != NULL)
                    {
                        boundaryTraversal(node->left, 1, false, ans);
                    }
                    boundaryTraversal(node->right, 1, true, ans);
                }
                else
                {
                    boundaryTraversal(node->left, 1, true, ans);
                }
                ans.push_back(node->data);
            }
        }
        else
        {
            if (dir == 0)
            {
                if (node->left != NULL)
                {
                    boundaryTraversal(node->left, dir, sameDir, ans);
                }
                if (node->right != NULL)
                {
                    boundaryTraversal(node->right, dir, sameDir, ans);
                }
            }
            else
            {
                if (node->left != NULL)
                {
                    boundaryTraversal(node->left, dir, sameDir, ans);
                }
                if (node->right != NULL)
                {
                    boundaryTraversal(node->right, dir, sameDir, ans);
                }
            }
        }
    }
    vector<int> boundary(Node *root)
    {
        vector<int> ans;
        ans.push_back(root->data);
        boundaryTraversal(root->left, 0, true, ans);
        boundaryTraversal(root->right, 1, true, ans);
        return ans;
    }
};

int main()
{

    return 0;
}