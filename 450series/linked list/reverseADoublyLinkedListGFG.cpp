#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
    Node(int x)
    {
        data = x;
        next = NULL;
        prev = NULL;
    }
};

// Node* reverseDLL(Node * head)
// {
//     if(head == NULL || head->next == NULL)
//         return head;
//     Node *p1 = head, *p2 = head;
//     while(p2->next != NULL)
//     {
//         p2 = p2->next;
//     }
//     while(true)
//     {
//         swap(p1->data, p2->data);
//         if(p1->next == p2 || p1 == p2)
//             break;
//         p1 = p1->next;
//         p2 = p2->prev;
//     }
//     return head;
// }

Node *reverseDLL(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        head->prev = NULL;
        return head;
    }

    Node *newHead = reverseDLL(head->next);
    head->next->next = head;
    head->prev = head->next;
    head->next = NULL;
    return newHead;
}

int main()
{

    return 0;
}