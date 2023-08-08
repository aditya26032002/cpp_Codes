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
    int getLevel(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }

        int leftLevel = getLevel(root->left);
        int rightLevel = getLevel(root->right);

        return max(leftLevel, rightLevel) + 1;
    }

    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        int level = getLevel(root);

        cout << level;
        vector<vector<int>> mat(level);
        if (root == NULL)
        {
            return mat;
        }

        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        int currLevel = 0;
        while (q.size() != 1)
        {
            if (q.front() == NULL)
            {
                q.pop();
                q.push(NULL);
                currLevel++;
                continue;
            }

            TreeNode *curr = q.front();
            q.pop();

            mat[level - currLevel - 1].push_back(curr->val);

            if (curr->left != NULL)
            {
                q.push(curr->left);
            }
            if (curr->right != NULL)
            {
                q.push(curr->right);
            }
        }
        return mat;
    }
};

int main()
{

    return 0;
}