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

        Node *newHead = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return newHead;
    }

    Node *findMid(Node *head)
    {
        Node *slow = head, *fast = head->next;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    // Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        Node *mid = findMid(head);
        mid->next = reverseList(mid->next);
        Node *p1 = head, *p2 = mid->next;
        while (p2 != NULL)
        {
            if (p1->data != p2->data)
                return 0;
            p1 = p1->next;
            p2 = p2->next;
        }
        return 1;
    }
};

int main()
{

    return 0;
}