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

class Solution
{
public:
    // Function to remove a loop in the linked list.
    void removeLoop(Node *head)
    {
        Node *slow = head, *fast = head;
        Node *prev = fast;
        while (1)
        {
            if (fast == NULL || fast->next == NULL)
                return;
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                break;
        }
        slow = head;
        while (slow != fast)
        {
            prev = fast;
            slow = slow->next;
            fast = fast->next;
        }
        prev->next = NULL;
    }
};

int main()
{

    return 0;
}