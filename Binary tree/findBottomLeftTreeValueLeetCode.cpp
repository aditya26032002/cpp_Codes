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
    int findBottomLeftValue(TreeNode *root)
    {
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);

        bool prevNull = true;
        int leftMost;
        while (q.size() != 1)
        {
            if (q.front() == NULL)
            {
                q.push(NULL);
                q.pop();
                prevNull = true;
                continue;
            }
            TreeNode *curr = q.front();
            q.pop();

            if (prevNull)
            {
                leftMost = curr->val;
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
        return leftMost;
    }
};

int main()
{

    return 0;
}