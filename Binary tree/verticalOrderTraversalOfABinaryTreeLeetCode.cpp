#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        map<int, map<int, vector<int>>> nodesMap;  // <index, map<level, vector> >
        queue<pair<TreeNode *, pair<int, int>>> q; // <node*, <index, level> >

        q.push(make_pair(root, make_pair(0, 0)));

        while (!q.empty())
        {
            TreeNode *currNode = q.front().first;
            int index = q.front().second.first;
            int level = q.front().second.second;
            q.pop();

            nodesMap[index][level].push_back(currNode->val);

            if (currNode->left != NULL)
            {
                q.push(make_pair(currNode->left, make_pair(index - 1, level + 1)));
            }
            if (currNode->right != NULL)
            {
                q.push(make_pair(currNode->right, make_pair(index + 1, level + 1)));
            }
        }

        int numOfIndexes = nodesMap.size();
        vector<vector<int>> ans(numOfIndexes);

        int i = 0;
        for (auto index : nodesMap)
        {
            for (auto level : index.second)
            {
                vector<int> levelVect = level.second;
                if (levelVect.size() > 1)
                {
                    sort(levelVect.begin(), levelVect.end());
                }
                ans[i].insert(ans[i].end(), levelVect.begin(), levelVect.end());
            }
            i++;
        }

        return ans;
    }
};

int main()
{

    return 0;
}