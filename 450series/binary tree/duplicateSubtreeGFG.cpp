#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
};
// you are required to complete this function
// the function and return an vector of Node
// which contains all the duplicate sub-tree

void preorderTraverse(Node *root, vector<int> &v)
{
    if (root == NULL)
        return;

    v.push_back(root->data);
    preorderTraverse(root->left, v);
    preorderTraverse(root->right, v);
}

void inorderTraverse(Node *root, vector<int> &v)
{
    if (root == NULL)
        return;

    inorderTraverse(root->left, v);
    v.push_back(root->data);
    inorderTraverse(root->right, v);
}

void helper(Node *root, map<pair<vector<int>, vector<int>>, int> &count, vector<Node *> &ans)
{
    if (root == NULL)
        return;

    pair<vector<int>, vector<int>> curr;
    preorderTraverse(root, curr.first);
    inorderTraverse(root, curr.second);

    count[curr]++;
    if (count[curr] == 2)
        ans.push_back(root);

    helper(root->left, count, ans);
    helper(root->right, count, ans);
}

vector<Node *> printAllDups(Node *root)
{
    map<pair<vector<int>, vector<int>>, int> count;
    vector<Node *> ans;
    helper(root, count, ans);
    return ans;
}

int main()
{

    return 0;
}