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
    Node *moveLastToFirst(Node *head)
    {
        if (head->next == NULL)
            return head;
        Node *ptr = head;
        while (ptr->next->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next->next = head;
        head = ptr->next;
        ptr->next = NULL;
        return head;
    }
};

int main()
{

    return 0;
}