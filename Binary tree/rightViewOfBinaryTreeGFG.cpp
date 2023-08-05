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
    // Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
        // Your Code here
        vector<int> ans;
        if (root == NULL)
        {
            return ans;
        }

        queue<Node *> q;
        q.push(root);
        q.push(NULL);

        while (q.size() != 1)
        {
            if (q.front() == NULL)
            {
                q.pop();
                q.push(NULL);
                continue;
            }

            Node *curr = q.front();
            q.pop();

            if (q.front() == NULL)
            {
                ans.push_back(curr->data);
            }

            if (curr->left != NULL)
            {
                q.push(curr->left);
            }
            if (curr->right != NULL)
            {
                q.push(curr->right);
            }
        }

        return ans;
    }

    /*
    void solve(Node *node, vector<int> &ans, int level)
    {
        if(node == NULL)
        {
            return;
        }

        if(level == ans.size())
        {
            ans.push_back(node->data);
        }

        solve(node->right, ans, level+1);
        solve(node->left, ans, level+1);
    }

    vector<int> rightView(Node *root)
    {
        vector<int> ans;
        solve(root, ans, 0);
        return ans;
    }
    */
};

int main()
{

    return 0;
}