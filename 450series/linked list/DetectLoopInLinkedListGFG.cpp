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

bool detectLoop(Node *head)
{
    Node *slow = head, *fast = head->next;
    while (slow != fast)
    {
        if (fast == NULL || fast->next == NULL)
            return 0;
        slow = slow->next;
        fast = fast->next->next;
    }
    return 1;
}

int main()
{

    return 0;
}