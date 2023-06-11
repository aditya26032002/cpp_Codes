#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
public:
    // Function to remove duplicates from unsorted linked list.
    Node *removeDuplicates(Node *head)
    {
        map<int, bool> present;
        Node *curr = head;
        present[head->data] = 1;
        while (curr != NULL && curr->next != NULL)
        {
            Node *nxt = curr->next;
            if (present[nxt->data])
                curr->next = nxt->next;
            else
            {
                present[nxt->data] = 1;
                curr = nxt;
            }
        }
        return head;
    }
};

int main()
{

    return 0;
}