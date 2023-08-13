#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

map<int, int> inorderMap(int in[], int n)
{
    map<int, int> nodesToIndex;
    for (int i = 0; i < n; i++)
    {
        nodesToIndex[in[i]] = i;
    }
    return nodesToIndex;
}

Node *solve(int in[], int post[], int inSt, int inEn, int postSt, int postEn, map<int, int> &nodesToIndex)
{
    if (inSt > inEn || postSt > postEn)
    {
        return NULL;
    }

    Node *root = new Node(post[postEn]);

    int index = nodesToIndex[post[postEn]];

    int leftCount = index - inSt;
    int rightCount = inEn - index;

    root->left = solve(in, post, inSt, index - 1, postSt, postSt + leftCount - 1, nodesToIndex);
    root->right = solve(in, post, index + 1, inEn, postSt + leftCount, postEn - 1, nodesToIndex);

    return root;
}

Node *buildTree(int in[], int post[], int n)
{
    map<int, int> nodesToIndex = inorderMap(in, n);
    return solve(in, post, 0, n - 1, 0, n - 1, nodesToIndex);
}

int main()
{

    return 0;
}