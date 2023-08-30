#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

class Solution
{
public:
    /* Should return minimum distance between a and b
    in a tree with given root*/

    int findData(Node *root, int &d)
    {
        if (root == NULL)
            return -1;

        if (root->data == d)
            return 0;

        int l = findData(root->left, d);
        int r = findData(root->right, d);

        if (l == -1 && r == -1)
            return -1;
        if (l != -1)
            return l + 1;
        return r + 1;
    }

    pair<bool, int> getHeight(Node *root, int &a, int &b, int &ans)
    {
        if (root == NULL)
            return {false, 0};

        if (root->data == a)
        {
            int len = findData(root, b);
            if (len != -1)
                ans = len;
            return {true, 1};
        }
        if (root->data == b)
        {
            int len = findData(root, a);
            if (len != -1)
                ans = len;
            return {true, 1};
        }
        pair<bool, int> l = getHeight(root->left, a, b, ans);
        pair<bool, int> r = getHeight(root->right, a, b, ans);
        if (l.first && r.first && ans == -1)
        {
            ans = l.second + r.second;
        }
        if (l.first)
            return {true, l.second + 1};
        if (r.first)
            return {true, r.second + 1};
        return {false, 0};
    }

    int findDist(Node *root, int a, int b)
    {
        int ans = -1;
        pair<bool, int> t = getHeight(root, a, b, ans);
        return ans;
    }
};

int main()
{

    return 0;
}