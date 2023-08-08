#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

class Solution
{
public:
    pair<int, int> solve(Node *curr) // pair<sum, height>
    {
        if (curr == NULL)
        {
            return make_pair(0, 0);
        }

        pair<int, int> leftData = solve(curr->left);
        pair<int, int> rightData = solve(curr->right);

        if (leftData.second > rightData.second)
        {
            return make_pair(leftData.first + curr->data, leftData.second + 1);
        }
        else if (leftData.second < rightData.second)
        {
            return make_pair(rightData.first + curr->data, rightData.second + 1);
        }
        else
        {
            if (leftData.first >= rightData.first)
            {
                return make_pair(leftData.first + curr->data, leftData.second + 1);
            }
            else
            {
                return make_pair(rightData.first + curr->data, rightData.second + 1);
            }
        }
    }

    int sumOfLongRootToLeafPath(Node *root)
    {
        pair<int, int> ans = solve(root);
        return ans.first;
    }

    /*
    void solve(Node *curr, int sum, int &maxSum, int len, int &maxLen) //pair<sum, height>
    {
        if(curr == NULL)
        {
            return;
        }
        if(curr->left == NULL && curr->right == NULL)
        {
            sum += curr->data;
            len++;
            if(len > maxLen)
            {
                maxLen = len;
                maxSum = sum;
            }
            else if(len == maxLen)
            {
                maxSum = max(maxSum, sum);
            }
            return;
        }

        sum += curr->data;
        len++;
        solve(curr->left, sum, maxSum, len, maxLen);
        solve(curr->right, sum, maxSum, len, maxLen);
    }

    int sumOfLongRootToLeafPath(Node *root)
    {
        int sum = 0, maxSum = 0;
        int len = 0, maxLen = 0;
        solve(root, sum, maxSum, len, maxLen);
        return maxSum;
    }
    */
};

int main()
{

    return 0;
}