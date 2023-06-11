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
    Node *reverseList(Node *head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        Node *temp = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return temp;
    }
    Node *addOne(Node *head)
    {
        head = reverseList(head);
        Node *ptr = head;
        Node *prev = head;
        int carry = 1;
        while (ptr != NULL)
        {
            int sum = (ptr->data + carry);
            ptr->data = sum % 10;
            carry = sum / 10;
            if (carry == 0)
                break;
            prev = ptr;
            ptr = ptr->next;
        }
        if (carry)
        {
            Node *newNode = new Node(carry);
            prev->next = newNode;
        }
        return reverseList(head);
    }
};

int main()
{

    return 0;
}