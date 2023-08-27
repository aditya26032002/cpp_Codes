#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

int getHeight(Node *root)
{
    if (root == NULL)
        return 0;

    int lH = getHeight(root->left);
    int rH = getHeight(root->right);
    return max(lH, rH) + 1;
}

void pushIntoMatrix(vector<vector<int>> &mat, Node *curr, int index, int maxIndex)
{
    if (curr == NULL)
    {
        return;
    }

    mat[maxIndex - index].push_back(curr->data);

    pushIntoMatrix(mat, curr->left, index - 1, maxIndex);
    pushIntoMatrix(mat, curr->right, index, maxIndex);
}

vector<int> diagonal(Node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;

    int height = getHeight(root);
    vector<vector<int>> tempAns(height + 1);

    pushIntoMatrix(tempAns, root, height / 2, height / 2);
    for (auto i : tempAns)
    {
        for (auto j : i)
        {
            ans.push_back(j);
        }
    }
    return ans;
}

int main()
{

    return 0;
}