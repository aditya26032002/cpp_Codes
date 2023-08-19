#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

class Solution
{
public:
    // Function to check whether a Binary Tree is BST or not.

    bool inRange(Node *root, int min, int max)
    {
        if (root == NULL)
            return true;

        if (root->data > min && root->data < max)
        {
            bool left = inRange(root->left, min, root->data);
            bool right = inRange(root->right, root->data, max);
            return left && right;
        }
        return false;
    }

    bool isBST(Node *root)
    {
        return inRange(root, INT_MIN, INT_MAX);
    }
    /*
    pair<int, int> getRange(Node *root, bool &ans)
    {
        if (root == NULL)
            return make_pair(-1, -1);

        if (ans)
        {
            int low = root->data, high = root->data;
            pair<int, int> leftRange = getRange(root->left, ans);
            pair<int, int> rightRange = getRange(root->right, ans);

            if (leftRange.second != -1)
            {
                if (leftRange.second >= root->data)
                    ans = false;
                low = min(low, leftRange.first);
            }
            if (rightRange.first != -1)
            {
                if (rightRange.first <= root->data)
                    ans = false;
                high = max(low, rightRange.first);
            }
            return make_pair(low, high);
        }
        else
        {
            return make_pair(-1, -1);
        }
    }

    bool isBST(Node *root)
    {
        bool ans = true;
        pair<int, int> tem = getRange(root, ans);
        return ans;
    }
    */
};

int main()
{

    return 0;
}