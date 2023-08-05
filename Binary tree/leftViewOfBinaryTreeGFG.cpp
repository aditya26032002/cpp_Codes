#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

// Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }

    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    bool prevNull = true;

    while (q.size() != 1)
    {
        if (q.front() == NULL)
        {
            q.pop();
            q.push(NULL);
            prevNull = true;
            continue;
        }

        Node *curr = q.front();
        q.pop();

        if (prevNull)
        {
            ans.push_back(curr->data);
            prevNull = false;
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

    solve(node->left, ans, level+1);
    solve(node->right, ans, level+1);
}

vector<int> leftView(Node *root)
{
    vector<int> ans;
    solve(root, ans, 0);
    return ans;
}
*/

int main()
{

    return 0;
}