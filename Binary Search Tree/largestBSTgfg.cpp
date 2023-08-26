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

class info
{
public:
    bool isBST;
    int mini;
    int maxi;
    int countNodes;
};

class Solution
{
public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST

    info solve(Node *root, int &maxNodes)
    {
        if (root == NULL)
        {
            return {true, INT_MAX, INT_MIN, 0};
        }

        info lft = solve(root->left, maxNodes);
        info rght = solve(root->right, maxNodes);

        info curr;
        curr.countNodes = lft.countNodes + rght.countNodes + 1;
        curr.mini = min(root->data, lft.mini);
        curr.maxi = max(root->data, rght.maxi);

        if (lft.isBST && rght.isBST && (root->data > lft.maxi && root->data < rght.mini))
        {
            curr.isBST = true;
        }
        else
            curr.isBST = false;

        if (curr.isBST)
        {
            maxNodes = max(maxNodes, curr.countNodes);
        }
        return curr;
    }

    int largestBst(Node *root)
    {
        if (root == NULL)
            return 0;
        int maxNodes = 1;
        info tmp = solve(root, maxNodes);
        return maxNodes;
    }

    /* // will give max number of nodes from any node to any node forming BST
        pair<int, pair<int, int>> solve(Node *root, int &maxNodes)
        {
            if (root->left == NULL && root->right == NULL)
                return {1, {root->data, root->data}};

            bool valid = true;
            int numOfNodes = 1;
            int leftRange = root->data, rightRange = root->data;
            if (root->left != NULL)
            {
                pair<int, pair<int, int>> lft = solve(root->left, maxNodes);

                numOfNodes += lft.first;

                pair<int, int> range = lft.second;
                if (range.first < root->data && range.second < root->data)
                    leftRange = range.first;
                else
                    valid = false;
            }
            if (root->right != NULL)
            {
                pair<int, pair<int, int>> rght = solve(root->right, maxNodes);

                numOfNodes += rght.first;

                pair<int, int> range = rght.second;
                if (range.first > root->data && range.second > root->data)
                    rightRange = range.second;
                else
                    valid = false;
            }

            if (valid)
            {
                maxNodes = max(maxNodes, numOfNodes);
                return {numOfNodes, {leftRange, rightRange}};
            }
            return {1, {root->data, root->data}};
        }

        int largestBst(Node *root)
        {
            if (root == NULL)
                return 0;
            int maxNodes = 1;
            pair<int, pair<int, int>> tmp = solve(root, maxNodes);
            return maxNodes;
        }
    */
};

int main()
{

    return 0;
}