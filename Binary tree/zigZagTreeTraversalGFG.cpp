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
    // Function to store the zig zag order traversal of tree in a list.
    vector<int> zigZagTraversal(Node *root)
    {
        vector<int> ans;
        deque<Node *> dq;

        dq.push_front(root);
        dq.push_back(NULL);

        bool flag = true;

        while (dq.size() != 1)
        {
            if (flag)
            {
                if (dq.front() == NULL)
                {
                    flag = !flag;
                    continue;
                }
                Node *temp = dq.front();
                dq.pop_front();

                ans.push_back(temp->data);

                if (temp->left != NULL)
                {
                    dq.push_back(temp->left);
                }
                if (temp->right != NULL)
                {
                    dq.push_back(temp->right);
                }
            }
            else
            {
                if (dq.back() == NULL)
                {
                    flag = !flag;
                    continue;
                }
                Node *temp = dq.back();
                dq.pop_back();

                ans.push_back(temp->data);

                if (temp->right != NULL)
                {
                    dq.push_front(temp->right);
                }
                if (temp->left != NULL)
                {
                    dq.push_front(temp->left);
                }
            }
        }
        return ans;
    }
};

int main()
{

    return 0;
}