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

// Function to remove duplicates from sorted linked list.
Node *removeDuplicates(Node *head)
{
    // your code goes here
    Node *curr = head;
    while (curr->next != NULL)
    {
        Node *next = curr->next;
        if (next->data == curr->data)
            curr->next = next->next;
        else
            curr = next;
    }
    return head;
}

int main()
{

    return 0;
}