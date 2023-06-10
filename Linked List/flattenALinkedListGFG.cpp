#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    struct Node *bottom;

    Node(int x)
    {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

Node *findMid(Node *head)
{
    Node *slow = head, *fast = head->bottom;
    while (fast != NULL && fast->bottom != NULL)
    {
        slow = slow->bottom;
        fast = fast->bottom->bottom;
    }
    return slow;
}
Node *mergeTwoSortedHalves(Node *left, Node *right)
{
    if (left == NULL)
        return right;
    if (right == NULL)
        return left;

    Node *ans = new Node(-1);
    Node *ptr = ans;
    while (left != NULL && right != NULL)
    {
        if (left->data < right->data)
        {
            ptr->bottom = left;
            ptr = left;
            left = left->bottom;
        }
        else
        {
            ptr->bottom = right;
            ptr = right;
            right = right->bottom;
        }
    }
    while (left != NULL)
    {
        ptr->bottom = left;
        ptr = left;
        left = left->bottom;
    }
    while (right != NULL)
    {
        ptr->bottom = right;
        ptr = right;
        right = right->bottom;
    }
    ptr = ans;
    ans = ans->bottom;
    delete ptr;
    return ans;
}

Node *mergeSort(Node *head)
{
    if (head == NULL || head->bottom == NULL)
        return head;

    Node *mid = findMid(head);
    Node *left = head;
    Node *right = mid->bottom;
    mid->bottom = NULL;
    left = mergeSort(left);
    right = mergeSort(right);
    return mergeTwoSortedHalves(left, right);
}

Node *flatten(Node *root)
{
    Node *nxtptr = root;
    while (nxtptr != NULL)
    {
        Node *btmptr = nxtptr;
        nxtptr = nxtptr->next;
        while (btmptr->bottom != NULL)
        {
            btmptr = btmptr->bottom;
        }
        btmptr->bottom = nxtptr;
    }
    return mergeSort(root);
}

int main()
{

    return 0;
}