#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;

    node(int x)
    {
        data = x;
        next = NULL;
    }

} *head;

class Solution
{
public:
    struct node *reverseList(struct node *head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        node *newHead = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return newHead;
    }

    struct node *reverse(struct node *head, int k)
    {
        if (head == NULL || head->next == NULL)
            return head;

        int x = k;
        node *tail = head;
        while (x - 1 > 0 && tail->next != NULL)
        {
            tail = tail->next;
            x--;
        }
        node *nexthead = reverse(tail->next, k);
        tail->next = NULL;
        node *newhead = reverseList(head);
        head->next = nexthead;
        return newhead;
    }
};

int main()
{

    return 0;
}