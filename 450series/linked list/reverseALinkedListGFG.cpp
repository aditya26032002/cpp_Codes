#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

class Solution
{
public:
    // Function to reverse a linked list.
    struct Node *reverseList(struct Node *head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        Node *newHead = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return newHead;
    }
    // struct Node *reverseList(struct Node *head)
    // {
    //     if (head == NULL || head->next == NULL)
    //         return head;
    //     Node *prev = NULL;
    //     Node *curr = head;
    //     Node *next = head->next;
    //     while (curr != NULL)
    //     {
    //         next = curr->next;
    //         curr->next = prev;
    //         prev = curr;
    //         curr = next;
    //     }
    //     return prev;
    // }
};

int main()
{

    return 0;
}