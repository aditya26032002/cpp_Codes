#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

Node *findIntersection(Node *head1, Node *head2)
{
    // Your Code Here
    Node *ans = new Node(-1);
    Node *ptr1 = head1, *ptr2 = head2, *ansptr = ans;
    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1->data == ptr2->data)
        {
            Node *newNode = new Node(ptr1->data);
            ansptr->next = newNode;
            ansptr = ansptr->next;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        else if (ptr1->data < ptr2->data)
            ptr1 = ptr1->next;
        else
            ptr2 = ptr2->next;
    }
    ansptr = ans;
    ans = ans->next;
    delete ansptr;
    return ans;
}

int main()
{

    return 0;
}