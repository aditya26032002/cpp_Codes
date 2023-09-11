#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

class Solution
{
public:
    // Return the Kth smallest element in the given BST

    void solve(Node *root, int &K, int &curr, int &ans)
    {
        if (root == NULL)
            return;

        int mark = -1;
        if (root->left == NULL)
        {
            mark = curr++;
        }
        else
            solve(root->left, K, curr, ans);

        if (mark == -1)
            mark = curr++;
        if (mark == K)
            ans = root->data;
        solve(root->right, K, curr, ans);
    }

    int KthSmallestElement(Node *root, int K)
    {
        int curr = 1;
        int ans = -1;
        solve(root, K, curr, ans);
        return ans;
    }
};

int main()
{

    return 0;
}