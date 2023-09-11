#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

class Solution
{
public:
    // The given root is the root of the Binary Tree
    // Return the root of the generated BST

    int numOfNodesInEachSide(Node *root, map<Node *, pair<int, int>> &leftRightCount, vector<int> &v)
    {
        if (root == NULL)
            return 0;

        v.push_back(root->data);

        int l = numOfNodesInEachSide(root->left, leftRightCount, v);
        int r = numOfNodesInEachSide(root->right, leftRightCount, v);

        leftRightCount[root] = {l, r};
        return l + r + 1;
    }

    Node *buildBST(Node *root, vector<int> &v, int s, int e, map<Node *, pair<int, int>> &leftRightCount)
    {
        if (root == NULL)
            return NULL;

        int l = leftRightCount[root].first;
        int r = leftRightCount[root].second;

        Node *rt = new Node(v[s + l]);

        rt->left = buildBST(root->left, v, s, s + l - 1, leftRightCount);
        rt->right = buildBST(root->right, v, s + l + 1, e, leftRightCount);
        return rt;
    }

    Node *binaryTreeToBST(Node *root)
    {
        vector<int> v;
        map<Node *, pair<int, int>> leftRightCount;
        int size = numOfNodesInEachSide(root, leftRightCount, v);
        sort(v.begin(), v.end());
        return buildBST(root, v, 0, size - 1, leftRightCount);
    }
};

int main()
{

    return 0;
}