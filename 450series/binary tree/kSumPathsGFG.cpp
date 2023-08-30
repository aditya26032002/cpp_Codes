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
    void solve(Node *root, int sum, int &k, map<int, int> &mp, int &count)
    {
        if (root == NULL)
            return;

        sum += root->data;
        if (sum == k)
            count++;
        if (mp.find(sum - k) != mp.end())
            count += mp[sum - k];

        mp[sum]++;
        solve(root->left, sum, k, mp, count);
        solve(root->right, sum, k, mp, count);
        mp[sum]--;
    }

    int sumK(Node *root, int k)
    {
        map<int, int> mp;
        int count = 0;
        solve(root, 0, k, mp, count);
        return count;
    }
};

int main()
{

    return 0;
}