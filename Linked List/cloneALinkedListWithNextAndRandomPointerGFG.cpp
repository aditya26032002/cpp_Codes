#include <bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    Node *next;
    Node *arb;

    Node(int x)
    {
        data = x;
        next = NULL;
        arb = NULL;
    }
};

class Solution
{
public:
    // Node *copyList(Node *head)
    // {
    //     map<Node *, Node *> nodesMap;
    //     Node *headptr = head;
    //     Node *clone = NULL;
    //     Node *cloneptr = clone;
    //     while (headptr != NULL)
    //     {
    //         Node *newNode = new Node(headptr->data);
    //         if (clone == NULL)
    //         {
    //             clone = newNode;
    //             cloneptr = clone;
    //             nodesMap[headptr] = cloneptr;
    //             headptr = headptr->next;
    //             continue;
    //         }
    //         cloneptr->next = newNode;
    //         nodesMap[headptr] = cloneptr->next;
    //         headptr = headptr->next;
    //         cloneptr = cloneptr->next;
    //     }
    //     headptr = head;
    //     cloneptr = clone;
    //     while (headptr != NULL)
    //     {
    //         if (headptr->arb != NULL)
    //         {
    //             cloneptr->arb = nodesMap[headptr->arb];
    //         }
    //         headptr = headptr->next;
    //         cloneptr = cloneptr->next;
    //     }
    //     return clone;
    // }
    Node *copyList(Node *head)
    {
        Node *clone = new Node(head->data);
        Node *prev = head;
        Node *curr = head->next;
        prev->next = clone;
        while (curr != NULL)
        {
            Node *newNode = new Node(curr->data);
            prev->next->next = curr;
            prev = curr;
            curr = curr->next;
            prev->next = newNode;
        }

        prev = head;
        curr = clone;
        while (1)
        {
            if (prev->arb != NULL)
                curr->arb = prev->arb->next;

            prev = prev->next->next;
            if (curr->next == NULL)
                break;
            curr = curr->next->next;
        }

        prev = head;
        curr = clone;
        while (curr != NULL)
        {
            prev->next = curr->next;
            prev = prev->next;
            if (prev != NULL)
                curr->next = prev->next;
            curr = curr->next;
        }
        return clone;
    }
};

int main()
{

    return 0;
}