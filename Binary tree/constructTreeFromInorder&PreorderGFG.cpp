#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

public:
    Node(int x)
    {
        this->data = x;
        this->left = NULL;
        this->right = NULL;
    }
};

class Solution
{
public:
    Node *solve(int in[], int pre[], int inSt, int inEn, int preSt, int preEn)
    {

        if (inSt > inEn)
        {
            return NULL;
        }

        int i = inSt;
        int count = 0;
        while (i <= inEn)
        {
            if (in[i] == pre[preSt])
            {
                break;
            }
            i++;
            count++;
        }

        Node *root = new Node(pre[preSt]);

        root->left = solve(in, pre, inSt, i - 1, preSt + 1, preSt + count);
        root->right = solve(in, pre, i + 1, inEn, preSt + count + 1, preEn);

        return root;
    }

    Node *buildTree(int in[], int pre[], int n)
    {
        return solve(in, pre, 0, n - 1, 0, n - 1);
    }
};

int main()
{

    return 0;
}