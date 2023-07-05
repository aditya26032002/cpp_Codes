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

// Function to find intersection point in Y shaped Linked Lists.

pair<int, int> getSize(Node *head1, Node *head2)
{
    Node *ptr1 = head1, *ptr2 = head2;
    int size1 = 0, size2 = 0;
    while (ptr1 != NULL && ptr2 != NULL)
    {
        size1++;
        size2++;
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    while (ptr1 != NULL)
    {
        size1++;
        ptr1 = ptr1->next;
    }
    while (ptr2 != NULL)
    {
        size2++;
        ptr2 = ptr2->next;
    }
    pair<int, int> ans = {size1, size2};
    return ans;
}
int intersectPoint(Node *head1, Node *head2)
{
    pair<int, int> sizes = getSize(head1, head2);
    int size1 = sizes.first, size2 = sizes.second;
    if (size1 > size2)
    {
        while (size1 != size2)
        {
            head1 = head1->next;
            size1--;
        }
    }
    else
    {
        while (size1 != size2)
        {
            head2 = head2->next;
            size2--;
        }
    }
    while (head1 != NULL)
    {
        if (head1 == head2)
            return head1->data;
        head1 = head1->next;
        head2 = head2->next;
    }
    return -1;
}

int main()
{

    return 0;
}