#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};

/*
We will traverse whole tree using morris traversal,
because if we return the ans as soon as we found it,
there may remain changes in the original tree which left unchanged.
*/
class Solution
{
public:
    int kthSmallest(TreeNode *root, int k)
    {
        int ans = -1;
        TreeNode *curr = root;
        while (curr != NULL)
        {
            if (curr->left == NULL)
            {
                if (k == 1)
                    ans = curr->val;
                curr = curr->right;
                k--;
            }
            else
            {
                TreeNode *ptr = curr->left;

                while (ptr->right != NULL && ptr->right != curr)
                    ptr = ptr->right;

                if (ptr->right == NULL)
                {
                    ptr->right = curr;
                    curr = curr->left;
                }
                else
                {
                    ptr->right = NULL;
                    if (k == 1)
                        ans = curr->val;
                    curr = curr->right;
                    k--;
                }
            }
        }
        return ans;
    }
};

int main()
{

    return 0;
}