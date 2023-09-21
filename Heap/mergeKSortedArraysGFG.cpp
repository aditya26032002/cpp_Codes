#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data, row, col;

    node(int data, int row, int col)
    {
        this->data = data;
        this->row = row;
        this->col = col;
    }
};

class compare
{
public:
    bool operator()(node *a, node *b)
    {
        return a->data > b->data;
    }
};

class Solution
{
public:
    // Function to merge k sorted arrays.
    // Time : O(r*c*Log(c)) Space : O(r) for pQueue and Space : O(r*c) for ans
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        priority_queue<node *, vector<node *>, compare> minPQ;
        for (int i = 0; i < arr.size(); i++)
        {
            node *t = new node(arr[i][0], i, 0);
            minPQ.push(t);
        }

        vector<int> ans;

        while (minPQ.size() > 0)
        {
            node *temp = minPQ.top();
            minPQ.pop();

            ans.push_back(temp->data);

            int r = temp->row, c = temp->col;
            if (c + 1 < arr[r].size())
            {
                node *nNode = new node(arr[r][c + 1], r, c + 1);
                minPQ.push(nNode);
            }
        }
        return ans;
    }

    /*
    // Time : O(r*c*Log(r*c)) Space : O(r*c)
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        priority_queue<int, vector<int>, greater<int>> minPQ;
        for (auto i : arr)
        {
            for (auto j : i)
                minPQ.push(j);
        }
        vector<int> ans;
        while (!minPQ.empty())
        {
            ans.push_back(minPQ.top());
            minPQ.pop();
        }
        return ans;
    }
    */
};

int main()
{

    return 0;
}