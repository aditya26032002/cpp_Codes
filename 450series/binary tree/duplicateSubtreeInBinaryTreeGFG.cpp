#include <bits/stdc++.h>
using namespace std;

struct Node
{
    char data;
    struct Node *left;
    struct Node *right;
};

class Solution
{
public:
    /*This function returns true if the tree contains
    a duplicate subtree of size 2 or more else returns false*/

    void inorder(Node *root, vector<int> &v)
    {
        if (root == NULL)
        {
            v.push_back(INT_MIN);
            return;
        }

        inorder(root->left, v);
        v.push_back(root->data);
        inorder(root->right, v);
    }

    void preorder(Node *root, vector<int> &v)
    {
        if (root == NULL)
        {
            v.push_back(INT_MIN);
            return;
        }

        v.push_back(root->data);
        preorder(root->left, v);
        preorder(root->right, v);
    }

    void solve(Node *root, map<vector<int>, bool> &inorderMap, bool &ans)
    {
        if (root == NULL)
            return;

        vector<int> v;
        inorder(root, v);
        if (v.size() > 3)
        {
            preorder(root, v);
            if (inorderMap.find(v) != inorderMap.end())
            {
                ans = true;
                return;
            }
            inorderMap[v] = true;
        }
        if (!ans)
            solve(root->left, inorderMap, ans);
        if (!ans)
            solve(root->right, inorderMap, ans);
    }

    int dupSub(Node *root)
    {
        bool ans = false;
        map<vector<int>, bool> inorderMap;
        solve(root->left, inorderMap, ans);
        solve(root->right, inorderMap, ans);
        return ans;
    }
};

int main()
{

    return 0;
}