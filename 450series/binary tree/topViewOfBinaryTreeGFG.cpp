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

    void getWidth(Node *root, int pos, int &minPos, int &maxPos)
    {
        if (root == NULL)
            return;

        if (pos < minPos)
            minPos = pos;
        if (pos > maxPos)
            maxPos = pos;

        getWidth(root->left, pos - 1, minPos, maxPos);
        getWidth(root->right, pos + 1, minPos, maxPos);
    }

    void solve(Node *root, vector<int> &ans, map<int, int> &indexMap)
    {
        queue<pair<Node *, int>> q;
        q.push(make_pair(root, 0));
        while (!q.empty())
        {
            pair<Node *, int> temp = q.front();
            q.pop();

            Node *curr = temp.first;
            int pos = temp.second;
            if (ans[indexMap[pos]] == -1)
                ans[indexMap[pos]] = curr->data;

            if (curr->left != NULL)
                q.push(make_pair(curr->left, pos - 1));
            if (curr->right != NULL)
                q.push(make_pair(curr->right, pos + 1));
        }
    }

    vector<int> topView(Node *root)
    {
        int minPos = 0, maxPos = 0;
        getWidth(root, 0, minPos, maxPos);
        int size = maxPos - minPos + 1;
        vector<int> ans(size, -1);

        map<int, int> indexMap;
        for (int i = minPos, j = 0; i <= maxPos; i++, j++)
        {
            indexMap[i] = j;
        }
        solve(root, ans, indexMap);
        return ans;
    }
};

int main()
{

    return 0;
}