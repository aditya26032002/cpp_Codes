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
    vector<int> ans;
    stack<queue<Node *>> st;
    queue<Node *> q;
    q.push(root);

    while (true)
    {
        st.push(q);
        int size = q.size();
        while (size--)
        {
            Node *ptr = q.front();
            q.pop();
            if (ptr->left != NULL)
            {
                q.push(ptr->left);
            }
            if (ptr->right != NULL)
            {
                q.push(ptr->right);
            }
        }
        if (q.empty())
        {
            break;
        }
    }
    while (!st.empty())
    {
        queue<Node *> temp = st.top();
        st.pop();
        while (!temp.empty())
        {
            ans.push_back((temp.front())->data);
            temp.pop();
        }
    }
    return ans;
}

int main()
{

    return 0;
}