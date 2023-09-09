#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    struct Node *next;
};
class Solution
{
public:
    // time: O(n) space: O(h)
    Node *solve(Node *root, Node *prev)
    {
        if (root == NULL)
            return NULL;

        Node *l = solve(root->left, root);
        Node *r = solve(root->right, prev);
        if (r != NULL)
            root->next = r;
        else
            root->next = prev;
        if (l != NULL)
            return l;
        return root;
    }

    void populateNext(Node *root)
    {
        Node *t = solve(root, NULL);
    }

    /* space: O(n)
    void solve(Node *root, vector<Node *> &v)
    {
        if (root == NULL)
            return;

        solve(root->left, v);
        v.push_back(root);
        solve(root->right, v);
    }

    void populateNext(Node *root)
    {
        vector<Node *> v;
        solve(root, v);
        v.push_back(NULL);
        for (int i = 0; i < v.size() - 1; i++)
            v[i]->next = v[i + 1];
    }
    */
};

int main()
{

    return 0;
}