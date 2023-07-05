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

void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    // your code goes here
    Node *slow = head, *fast = head;
    Node *prev;
    while (1)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            break;
    }
    prev->next = NULL;
    slow = head, fast = head->next;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    *head1_ref = head;
    *head2_ref = slow->next;
    slow->next = head;
    prev->next = *head2_ref;
}

int main()
{

    return 0;
}