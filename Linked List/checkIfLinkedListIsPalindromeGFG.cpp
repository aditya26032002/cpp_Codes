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
    void reverse(Node *head, Node *&newHead)
    {
        if (head->next == NULL)
        {
            newHead = head;
            return;
        }

        reverse(head->next, newHead);
        head->next->next = head;
        head->next = NULL;
    }
    // Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        Node *slow = head, *fast = head, *prevOfSlow = head;
        while (fast != NULL && fast->next != NULL)
        {
            prevOfSlow = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        Node *newMid = NULL;
        reverse(slow, newMid);
        prevOfSlow->next = newMid;
        Node *ptr1 = head, *ptr2 = newMid;
        while (ptr1 != newMid)
        {
            if (ptr1->data != ptr2->data)
                return false;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        return true;
    }
};

int main()
{

    return 0;
}