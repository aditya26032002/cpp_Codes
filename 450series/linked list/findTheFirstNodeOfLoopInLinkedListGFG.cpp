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
    // Function to find first node if the linked list has a loop.
    int findFirstNode(Node *head)
    {
        Node *slow = head, *fast = head;
        while (1)
        {
            if (fast == NULL || fast->next == NULL)
                return -1;
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                slow = head;
                while (1)
                {
                    if (slow == fast)
                        return slow->data;
                    slow = slow->next;
                    fast = fast->next;
                }
            }
        }
    }
};

int main()
{

    return 0;
}