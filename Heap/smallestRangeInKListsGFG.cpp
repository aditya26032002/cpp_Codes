#include <bits/stdc++.h>
using namespace std;

#define N 1000

class Node
{
public:
    int data, row, col;
    Node(int data, int row, int col)
    {
        this->data = data;
        this->row = row;
        this->col = col;
    }
};

class compare
{
public:
    bool operator()(Node *a, Node *b)
    {
        return (a->data > b->data);
    }
};

class Solution
{
public:
    pair<int, int> findSmallestRange(int KSortedArray[][N], int n, int k)
    {
        priority_queue<Node *, vector<Node *>, compare> minHeap;
        int mini = INT_MAX, maxi = INT_MIN;
        for (int i = 0; i < k; i++)
        {
            if (KSortedArray[i][0] > maxi)
                maxi = KSortedArray[i][0];
            Node *n = new Node(KSortedArray[i][0], i, 0);
            minHeap.push(n);
        }
        mini = minHeap.top()->data;
        int range = abs(maxi - mini);
        int ansMin = mini, ansMax = maxi;

        while (minHeap.size() == k)
        {
            Node *t = minHeap.top();
            minHeap.pop();
            int d = t->data, r = t->row, c = t->col;
            if (c + 1 < k)
            {
                Node *n = new Node(KSortedArray[r][c + 1], r, c + 1);
                minHeap.push(n);

                mini = minHeap.top()->data;

                if (n->data > maxi)
                    maxi = n->data;

                delete t;

                int currRange = abs(mini - maxi);
                if (currRange < range)
                {
                    range = currRange;
                    ansMin = mini;
                    ansMax = maxi;
                }
            }
        }
        return {ansMin, ansMax};
    }
};

int main()
{
    int n, k;
    cin >> n >> k;
    int arr[n][N];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            cin >> arr[i][j];
        }
    }
    Solution s;
    pair<int, int> ans = s.findSmallestRange(arr, n, k);
    cout << ans.first << " " << ans.second << endl;
    return 0;
}