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
    pair<bool, bool> findData(Node *curr, int &n1, int &n2, Node *&ans)
    {
        if (curr == NULL)
        {
            return make_pair(false, false);
        }
        pair<bool, bool> found(false, false); // n1,n2

        if (curr->data == n1)
        {
            found.first = true;
        }
        if (curr->data == n2)
        {
            found.second = true;
        }

        pair<bool, bool> leftSearch = findData(curr->left, n1, n2, ans);
        pair<bool, bool> rightSearch = findData(curr->right, n1, n2, ans);

        found.first = (leftSearch.first || rightSearch.first || found.first);
        found.second = (leftSearch.second || rightSearch.second || found.second);

        if (found.first && found.second && ans == NULL)
        {
            ans = curr;
        }
        return found;
    }
    // Function to return the lowest common ancestor in a Binary Tree.
    Node *lca(Node *root, int n1, int n2)
    {
        Node *ans = NULL;
        pair<bool, bool> found = findData(root, n1, n2, ans);
        return ans;
    }

    /*
    Node* findNodes(Node *curr, int &n1, int &n2)
    {
        if(curr == NULL)
        {
            return NULL;
        }

        if(curr->data == n1 || curr->data == n2)
        {
            return curr;
        }

        Node* findLeft = findNodes(curr->left, n1, n2);
        Node* findRight = findNodes(curr->right, n1, n2);

        if(findLeft != NULL && findRight != NULL)
        {
            return curr;
        }
        if(findLeft != NULL)
        {
            return findLeft;
        }
        if(findRight != NULL)
        {
            return findRight;
        }
        return NULL;
    }
    //Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root ,int n1 ,int n2 )
    {
       return findNodes(root, n1, n2);
    }
    */
};

int main()
{

    return 0;
}