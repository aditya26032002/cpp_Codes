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

void solve(Node *root, vector<int> &v, int h, int &maxHeight)
{
    if (root == NULL)
        return;

    if (h > maxHeight)
    {
        maxHeight = h;
        v.push_back(root->data);
    }
    solve(root->left, v, h + 1, maxHeight);
    solve(root->right, v, h + 1, maxHeight);
}

vector<int> leftView(Node *root)
{
    vector<int> ans;
    int maxH = 0;
    solve(root, ans, 1, maxH);
    return ans;
}

int main()
{

    return 0;
}