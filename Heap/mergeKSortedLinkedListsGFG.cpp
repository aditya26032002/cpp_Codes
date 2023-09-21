#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class compare
{
public:
    bool operator()(Node *a, Node *b)
    {
        return a->data > b->data;
    }
};

class Solution
{
public:
    // Function to merge K sorted linked list.
    // Time : O(nLog(k)) Space : O(k)
    Node *mergeKLists(Node *arr[], int K)
    {
        priority_queue<Node *, vector<Node *>, compare> minPQ;
        for (int i = 0; i < K; i++)
        {
            minPQ.push(arr[i]);
        }

        Node *root = NULL;
        Node *ptr = NULL;

        while (minPQ.size() > 0)
        {
            Node *temp = minPQ.top();
            minPQ.pop();
            if (root == NULL)
            {
                root = temp;
                ptr = temp;
            }
            else
            {
                ptr->next = temp;
                ptr = temp;
            }
            if (temp->next != NULL)
                minPQ.push(temp->next);
        }

        return root;
    }
};

int main()
{

    return 0;
}