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
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        // Your code here
        vector<int> ans;

        map<int, int> indexTopElement;
        queue<pair<Node *, int>> q;
        q.push(make_pair(root, 0));

        while (!q.empty())
        {
            Node *currNode = q.front().first;
            int index = q.front().second;
            q.pop();

            if (indexTopElement[index] == NULL)
            {
                indexTopElement[index] = currNode->data;
            }

            if (currNode->left != NULL)
            {
                q.push(make_pair(currNode->left, index - 1));
            }
            if (currNode->right != NULL)
            {
                q.push(make_pair(currNode->right, index + 1));
            }
        }

        for (auto i : indexTopElement)
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