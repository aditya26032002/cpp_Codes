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
    // Function to store the zig zag order traversal of tree in a list.
    vector<int> zigZagTraversal(Node *root)
    {
        queue<Node *> q;
        q.push(root);
        q.push(NULL);
        bool toreverse = false;
        vector<int> ans;
        while (true)
        {
            vector<int> tempAns;
            while (q.front() != NULL)
            {
                Node *temp = q.front();
                q.pop();
                tempAns.push_back(temp->data);

                if (temp->left != NULL)
                    q.push(temp->left);
                if (temp->right != NULL)
                    q.push(temp->right);
            }
            if (toreverse)
            {
                reverse(tempAns.begin(), tempAns.end());
            }
            ans.insert(ans.end(), tempAns.begin(), tempAns.end());
            toreverse = !toreverse;

            if (q.size() == 1)
                break;
            else
            {
                q.pop();
                q.push(NULL);
            }
        }
        return ans;
    }
};

int main()
{

    return 0;
}