#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> ans;
        if (root == NULL)
        {
            return ans;
        }

        queue<TreeNode *> q;
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

            TreeNode *curr = q.front();
            q.pop();

            if (q.front() == NULL)
            {
                ans.push_back(curr->val);
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
    void solve(TreeNode *root, vector<int> &v, int h, int &maxHeight)
    {
        if (root == NULL)
            return;

        if (h > maxHeight)
        {
            maxHeight = h;
            v.push_back(root->val);
        }
        solve(root->right, v, h + 1, maxHeight);
        solve(root->left, v, h + 1, maxHeight);
    }
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> ans;
        int maxH = 0;
        solve(root, ans, 1, maxH);
        return ans;
    }
    */
};

int main()
{

    return 0;
}