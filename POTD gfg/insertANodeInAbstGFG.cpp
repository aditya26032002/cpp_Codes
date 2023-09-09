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
    Node *insert(Node *node, int data)
    {
        if (node == NULL)
        {
            Node *n = new Node(data);
            return n;
        }

        if (node->data == data)
            return node;
        if (node->data > data)
            node->left = insert(node->left, data);
        else
            node->right = insert(node->right, data);
    }
};

int main()
{

    return 0;
}