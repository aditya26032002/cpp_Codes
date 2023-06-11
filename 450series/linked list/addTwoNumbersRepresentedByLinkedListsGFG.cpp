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
    // Function to add two numbers represented by linked list.
    Node *reverse(Node *head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        Node *temp = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return temp;
    }
    struct Node *addTwoLists(struct Node *first, struct Node *second)
    {
        first = reverse(first);
        second = reverse(second);

        Node *ans = new Node(-1);
        Node *ptr1 = first, *ptr2 = second, *ansptr = ans;

        int carry = 0;
        while (ptr1 != NULL && ptr2 != NULL)
        {
            int sum = ptr1->data + ptr2->data + carry;
            Node *newNode = new Node(sum % 10);
            ansptr->next = newNode;
            carry = sum / 10;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
            ansptr = ansptr->next;
        }
        while (ptr1 != NULL)
        {
            int sum = ptr1->data + carry;
            Node *newNode = new Node(sum % 10);
            ansptr->next = newNode;
            carry = sum / 10;
            ptr1 = ptr1->next;
            ansptr = ansptr->next;
        }
        while (ptr2 != NULL)
        {
            int sum = ptr2->data + carry;
            Node *newNode = new Node(sum % 10);
            ansptr->next = newNode;
            carry = sum / 10;
            ptr2 = ptr2->next;
            ansptr = ansptr->next;
        }
        if (carry)
        {
            Node *newNode = new Node(carry);
            ansptr->next = newNode;
        }
        ansptr = ans;
        ans = ans->next;
        delete ansptr;
        return reverse(ans);
    }
};

int main()
{

    return 0;
}