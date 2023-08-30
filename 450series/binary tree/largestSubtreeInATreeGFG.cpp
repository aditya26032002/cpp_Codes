#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

class Solution
{
public:
    // Function to find largest subtree sum.

    int sum(Node *root, int &maxSum)
    {
        if (root == NULL)
            return 0;

        int lf = sum(root->left, maxSum);
        int rt = sum(root->right, maxSum);

        int s = lf + rt + root->data;
        maxSum = max(s, maxSum);
        return s;
    }
    int findLargestSubtreeSum(Node *root)
    {
        int ans = INT_MIN;
        int s = sum(root, ans);
        return ans;
    }
};

int main()
{

    return 0;
}