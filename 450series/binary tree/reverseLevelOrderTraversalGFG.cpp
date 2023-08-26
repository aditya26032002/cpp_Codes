#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};
vector<int> reverseLevelOrder(Node *root)
{
    // code here
    stack<queue<Node *>> st;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        st.push(q);
        queue<Node *> newq;
        while (!q.empty())
        {
            Node *temp = q.front();
            q.pop();
            if (temp->left != NULL)
                newq.push(temp->left);
            if (temp->right != NULL)
                newq.push(temp->right);
        }
        q = newq;
    }

    vector<int> ans;
    while (!st.empty())
    {
        queue<Node *> q = st.top();
        st.pop();
        while (!q.empty())
        {
            Node *temp = q.front();
            q.pop();
            ans.push_back(temp->data);
        }
    }
    return ans;
}

int main()
{

    return 0;
}