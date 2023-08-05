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
    vector<int> bottomView(Node *root)
    {
        vector<int> ans;
        if (root == NULL)
        {
            return ans;
        }

        map<int, int> indexLastElement;
        queue<pair<Node *, int>> q;
        q.push(make_pair(root, 0));

        while (!q.empty())
        {
            Node *curr = q.front().first;
            int index = q.front().second;
            q.pop();

            indexLastElement[index] = curr->data;

            if (curr->left != NULL)
            {
                q.push(make_pair(curr->left, index - 1));
            }

            if (curr->right != NULL)
            {
                q.push(make_pair(curr->right, index + 1));
            }
        }

        for (auto i : indexLastElement)
        {
            ans.push_back(i.second);
        }

        return ans;
    }
};

int main()
{

    return 0;
}