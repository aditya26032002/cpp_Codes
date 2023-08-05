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
    // Function to find the vertical order traversal of Binary Tree.

    void getWidth(Node *node, int &left, int &right, int curr)
    {
        if (node == NULL)
        {
            return;
        }
        left = min(left, curr);
        right = max(right, curr);
        getWidth(node->left, left, right, curr - 1);
        getWidth(node->right, left, right, curr + 1);
    }

    void pushData(Node *root, vector<vector<int>> &tempAns, map<int, int> &indexMap)
    {
        queue<Node *> q;
        queue<int> curr;
        q.push(root);
        curr.push(0);
        while (!q.empty())
        {
            Node *temp = q.front();
            int index = curr.front();
            q.pop();
            curr.pop();

            tempAns[indexMap[index]].push_back(temp->data);

            if (temp->left != NULL)
            {
                q.push(temp->left);
                curr.push(index - 1);
            }
            if (temp->right != NULL)
            {
                q.push(temp->right);
                curr.push(index + 1);
            }
        }
    }

    vector<int> flattenTheMatrix(vector<vector<int>> &tempAns)
    {
        vector<int> ans;
        for (auto i : tempAns)
        {
            for (auto j : i)
            {
                ans.push_back(j);
            }
        }
        return ans;
    }

    vector<int> verticalOrder(Node *root)
    {
        int left = 0, right = 0;
        getWidth(root, left, right, 0);

        int width = abs(left) + abs(right) + 1;
        vector<vector<int>> tempAns(width);

        map<int, int> indexMap;
        for (int i = 0; left <= right; i++, left++)
        {
            indexMap[left] = i;
        }

        pushData(root, tempAns, indexMap);

        vector<int> ans = flattenTheMatrix(tempAns);
        return ans;
    }

    /*
    vector<int> verticalOrder(Node *root)
    {
        vector<int> ans;

        if(root == NULL)
        {
            return ans;
        }

        map<int, map<int, vector<int>>> nodesMap; // <index, map<level, vector> >
        queue<pair<Node*, pair<int, int>>> q; // <node*, <index, level> >

        q.push(make_pair(root, make_pair(0, 0)));

        while(!q.empty())
        {
            Node *currNode = q.front().first;
            int index = q.front().second.first;
            int level = q.front().second.second;
            q.pop();

            nodesMap[index][level].push_back(currNode->data);

            if(currNode->left != NULL)
            {
                q.push(make_pair(currNode->left, make_pair(index-1, level+1)));
            }
            if(currNode->right != NULL)
            {
                q.push(make_pair(currNode->right, make_pair(index+1, level+1)));
            }
        }

        for(auto index : nodesMap)
        {
            for(auto level : index.second)
            {
                for(auto element : level.second)
                {
                    ans.push_back(element);
                }
            }
        }

        return ans;
    }
    */
};

class Solution
{
public:
    // Function to find the vertical order traversal of Binary Tree.

    void getWidth(Node *node, int &left, int &right, int curr)
    {
        if (node == NULL)
        {
            return;
        }
        left = min(left, curr);
        right = max(right, curr);
        getWidth(node->left, left, right, curr - 1);
        getWidth(node->right, left, right, curr + 1);
    }

    void pushData(Node *root, vector<vector<int>> &tempAns, map<int, int> &indexMap)
    {
        queue<Node *> q;
        queue<int> curr;
        q.push(root);
        curr.push(0);
        while (!q.empty())
        {
            Node *temp = q.front();
            int index = curr.front();
            q.pop();
            curr.pop();

            tempAns[indexMap[index]].push_back(temp->data);

            if (temp->left != NULL)
            {
                q.push(temp->left);
                curr.push(index - 1);
            }
            if (temp->right != NULL)
            {
                q.push(temp->right);
                curr.push(index + 1);
            }
        }
    }

    vector<int> flattenTheMatrix(vector<vector<int>> &tempAns)
    {
        vector<int> ans;
        for (auto i : tempAns)
        {
            for (auto j : i)
            {
                ans.push_back(j);
            }
        }
        return ans;
    }

    vector<int> verticalOrder(Node *root)
    {
        int left = 0, right = 0;
        getWidth(root, left, right, 0);

        int width = abs(left) + abs(right) + 1;
        vector<vector<int>> tempAns(width);

        map<int, int> indexMap;
        for (int i = 0; left <= right; i++, left++)
        {
            indexMap[left] = i;
        }

        pushData(root, tempAns, indexMap);

        vector<int> ans = flattenTheMatrix(tempAns);
        return ans;
    }
};

int main()
{

    return 0;
}