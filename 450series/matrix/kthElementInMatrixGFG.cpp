#include <bits/stdc++.h>
using namespace std;

#define MAX 50

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

int kthSmallest(int mat[MAX][MAX], int n, int k)
{
    priority_queue<node *, vector<node *>, compare> minHeap;
    node *smallest = new node(mat[0][0], 0, 0);
    minHeap.push(smallest);
    mat[0][0] = -1;
    int ans = -1;
    while (k--)
    {
        node *curr = minHeap.top();
        ans = curr->data;
        minHeap.pop();
        int currRow = curr->row, currCol = curr->col;
        if (currRow + 1 < n && mat[currRow + 1][currCol] != -1)
        {
            node *newNode = new node(mat[currRow + 1][currCol], currRow + 1, currCol);
            mat[currRow + 1][currCol] = -1;
            minHeap.push(newNode);
        }
        if (currCol + 1 < n && mat[currRow][currCol + 1] != -1)
        {
            node *newNode = new node(mat[currRow][currCol + 1], currRow, currCol + 1);
            mat[currRow][currCol + 1] = -1;
            minHeap.push(newNode);
        }
        delete curr;
    }
    return ans;
}

int main()
{

    return 0;
}