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
    // Time : O(n), Space : O(n)
    void solve(Node *curr, int k, map<int, int> &mp, int prevSum, int &count)
    {
        if (curr == NULL)
        {
            return;
        }

        int currSum = prevSum + curr->data;

        if (mp[currSum - k] != NULL)
        {
            count += mp[currSum - k];
        }

        mp[currSum]++;

        if (currSum == k)
            count++;

        solve(curr->left, k, mp, currSum, count);
        solve(curr->right, k, mp, currSum, count);

        mp[currSum]--;
    }

    int sumK(Node *root, int k)
    {
        int count = 0;
        map<int, int> mp;
        solve(root, k, mp, 0, count);

        return count;
    }
    /*
    // time : O(n^2)
    int countSum(vector<int> &path, int k)
    {
        int count = 0;
        int sum = 0;
        int size = path.size();
        for (int i = size - 1; i >= 0; i--)
        {
            sum += path[i];
            if (sum == k)
            {
                count++;
            }
        }
        return count;
    }

    void solve(Node *curr, int k, int &count, vector<int> &path)
    {
        if (curr == NULL)
        {
            return;
        }

        path.push_back(curr->data);

        solve(curr->left, k, count, path);
        solve(curr->right, k, count, path);

        count += countSum(path, k);

        path.pop_back();
    }

    int sumK(Node *root, int k)
    {
        int count = 0;
        vector<int> path;
        solve(root, k, count, path);
        return count;
    }
    */
};

int main()
{

    return 0;
}