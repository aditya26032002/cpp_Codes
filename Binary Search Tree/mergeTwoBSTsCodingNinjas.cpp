#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

void inorder(TreeNode *root, vector<int> &v)
{
    if (root == NULL)
        return;

    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

vector<int> mergeBST(TreeNode *root1, TreeNode *root2)
{
    vector<int> inRoot1;
    vector<int> inRoot2;
    inorder(root1, inRoot1);
    inorder(root2, inRoot2);

    vector<int> ans;
    int i = 0, j = 0, size1 = inRoot1.size(), size2 = inRoot2.size();
    while (i < size1 && j < size2)
    {
        if (inRoot1[i] < inRoot2[j])
            ans.push_back(inRoot1[i++]);
        else
            ans.push_back(inRoot2[j++]);
    }
    while (i < size1)
    {
        ans.push_back(inRoot1[i++]);
    }
    while (j < size2)
    {
        ans.push_back(inRoot2[j++]);
    }
    return ans;
}

int main()
{

    return 0;
}