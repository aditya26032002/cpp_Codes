#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

void getLevel(Node *root, int &level, int currLevel)
{
    if (root == NULL)
    {
        return;
    }

    level = max(level, currLevel);

    getLevel(root->left, level, currLevel + 1);
    getLevel(root->right, level, currLevel + 1);
}

void pushIntoMatrix(vector<vector<int>> &mat, Node *curr, int index, int maxIndex)
{
    if (curr == NULL)
    {
        return;
    }

    mat[maxIndex - index].push_back(curr->data);

    pushIntoMatrix(mat, curr->left, index - 1, maxIndex);
    pushIntoMatrix(mat, curr->right, index, maxIndex);
}

vector<int> diagonal(Node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }

    int level = 0;
    getLevel(root, level, 1);

    vector<vector<int>> mat(level + 1);
    pushIntoMatrix(mat, root, level / 2, level / 2);

    for (auto i : mat)
    {
        for (auto j : i)
        {
            ans.push_back(j);
        }
    }
    return ans;
}

/*
void getLevelAndWidth(Node *root, int &left, int &right, int &level, int dist, int currLevel)
{
    if (root == NULL)
    {
        return;
    }

    left = min(left, dist);
    right = max(right, dist);
    level = max(level, currLevel);

    getLevelAndWidth(root->left, left, right, level, dist - 1, currLevel + 1);
    getLevelAndWidth(root->right, left, right, level, dist + 1, currLevel + 1);
}

void diagonalTraveral(map<int, map<int, vector<int>>> &nodesData, int &left, int &right, int &level, vector<int> &ans)
{
    int i = right;
    while (i >= left)
    {
        int x = i, y = 0;
        while (x <= right && y <= level)
        {
            for (auto element : nodesData[x][y])
            {
                ans.push_back(element);
            }
            x++;
            y++;
        }
        i--;
    }

    int j = 1;
    while (j <= level)
    {
        int x = left, y = j;
        while (x <= right && y <= level)
        {
            for (auto element : nodesData[x][y])
            {
                ans.push_back(element);
            }
            x++;
            y++;
        }
        j++;
    }
}

vector<int> diagonal(Node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }

    map<int, map<int, vector<int>>> nodesData;
    queue<pair<Node *, pair<int, int>>> q;
    q.push(make_pair(root, make_pair(0, 0)));

    while (!q.empty())
    {
        Node *curr = q.front().first;
        int index = q.front().second.first;
        int level = q.front().second.second;
        q.pop();

        nodesData[index][level].push_back(curr->data);

        if (curr->left != NULL)
        {
            q.push(make_pair(curr->left, make_pair(index - 1, level + 1)));
        }
        if (curr->right != NULL)
        {
            q.push(make_pair(curr->right, make_pair(index + 1, level + 1)));
        }
    }

    int left = 0, right = 0, level = 0;
    getLevelAndWidth(root, left, right, level, 0, 0);

    diagonalTraveral(nodesData, left, right, level, ans);

    return ans;
}
*/

int main()
{

    return 0;
}