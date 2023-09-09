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

// return the Kth largest element in the given BST rooted at 'root'
class Solution
{
public:
    void solve(Node *root, int &curr, int &K, int &ans)
    {
        if (root == NULL)
            return;

        int markCurr = -1;
        if (root->right == NULL)
        {
            markCurr = curr++;
        }
        else
            solve(root->right, curr, K, ans);

        if (markCurr == -1)
            markCurr = curr++;

        if (markCurr == K)
            ans = root->data;

        solve(root->left, curr, K, ans);
    }
    int kthLargest(Node *root, int K)
    {
        int ans = -1, curr = 1;
        solve(root, curr, K, ans);
        return ans;
    }
};

int main()
{

    return 0;
}