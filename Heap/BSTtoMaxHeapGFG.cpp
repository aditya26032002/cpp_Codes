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
    void inorder(Node *root, vector<Node *> &arr)
    {
        if (root == NULL)
            return;

        inorder(root->left, arr);
        arr.push_back(root);
        inorder(root->right, arr);
        root->left = root->right = NULL;
    }

    Node *buildtree(vector<Node *> &arr, int s, int e)
    {
        if (s > e)
            return NULL;

        if (s == e)
            return arr[s];

        Node *curr = arr[e];
        int mid = s + (e - 1 - s) / 2;
        curr->left = buildtree(arr, s, mid);
        curr->right = buildtree(arr, mid + 1, e - 1);
        return curr;
    }

    void convertToMaxHeapUtil(Node *root)
    {
        vector<Node *> arr;
        inorder(root, arr);

        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] == root)
            {
                swap(arr[i], arr[arr.size() - 1]);
                swap(arr[i]->data, arr[arr.size() - 1]->data);
                break;
            }
        }

        buildtree(arr, 0, arr.size() - 1);
    }
};

int main()
{

    return 0;
}