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
    int countNodes(Node *root)
    {
        if (root == NULL)
            return 0;

        int l = countNodes(root->left);
        int r = countNodes(root->right);
        return l + r + 1;
    }

    bool checkCBT(Node *root, int &totNodes, int i)
    {
        if (root == NULL)
            return true;

        if (i > totNodes)
            return false;

        return checkCBT(root->left, totNodes, 2 * i) && checkCBT(root->right, totNodes, 2 * i + 1);
    }

    void putIntoArray(Node *root, int arr[], int i)
    {
        if (root == NULL)
            return;

        arr[i] = root->data;
        putIntoArray(root->left, arr, 2 * i + 1);
        putIntoArray(root->right, arr, 2 * i + 2);
    }

    bool checkHeap(int arr[], int &size, int i)
    {
        if (i >= size)
            return true;

        int l = 2 * i + 1, r = 2 * i + 2;
        int greatest = i;

        if (l < size && arr[l] > arr[i])
            return false;
        if (r < size && arr[r] > arr[i])
            return false;

        return checkHeap(arr, size, l) && checkHeap(arr, size, r);
    }

    bool isHeap(struct Node *tree)
    {
        int size = countNodes(tree);
        if (checkCBT(tree, size, 1) == false)
            return false;

        int arr[size] = {0};
        putIntoArray(tree, arr, 0);
        return checkHeap(arr, size, 0);
    }
};

int main()
{

    return 0;
}