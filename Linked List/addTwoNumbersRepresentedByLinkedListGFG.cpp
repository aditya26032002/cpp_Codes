#include <bits/stdc++.h>
using namespace std;

//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
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

struct Node *buildList(int size)
{
    int val;
    cin >> val;

    Node *head = new Node(val);
    Node *tail = head;

    for (int i = 0; i < size - 1; i++)
    {
        cin >> val;
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node *n)
{
    while (n)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
public:
    // Function to add two numbers represented by linked list.

    void reverseList(struct Node *head, struct Node *&newHead, int &size)
    {
        size++;
        if (head->next == NULL)
        {
            newHead = head;
            return;
        }
        reverseList(head->next, newHead, size);
        head->next->next = head;
        head->next = NULL;
    }
    struct Node *addTwoLists(struct Node *first, struct Node *second)
    {
        struct Node *ptr1 = NULL, *ptr2 = NULL;
        int size1 = 0, size2 = 0;
        reverseList(first, ptr1, size1);
        reverseList(second, ptr2, size2);
        // cout<<size1<<" "<<size2<<endl;
        if (size1 >= size2)
        {
            struct Node *sumptr = ptr1;
            int carry = 0;
            while (ptr2 != NULL)
            {
                int sum = sumptr->data + ptr2->data + carry;
                carry = sum / 10;
                sumptr->data = sum % 10;
                if (sumptr->next == NULL && carry != 0)
                {
                    struct Node *newNode = new Node(carry);
                    sumptr->next = newNode;
                    sumptr = sumptr->next;
                }
                sumptr = sumptr->next;
                ptr2 = ptr2->next;
            }
            while (sumptr != NULL)
            {
                int sum = sumptr->data + carry;
                carry = sum / 10;
                sumptr->data = sum % 10;
                if (sumptr->next == NULL && carry != 0)
                {
                    struct Node *newNode = new Node(carry);
                    sumptr->next = newNode;
                    break;
                }
                sumptr = sumptr->next;
            }
            reverseList(ptr1, first, carry);
            return first;
        }
        else
        {
            struct Node *sumptr = ptr2;
            int carry = 0;
            while (ptr1 != NULL)
            {
                int sum = sumptr->data + ptr1->data + carry;
                carry = sum / 10;
                sumptr->data = sum % 10;
                sumptr = sumptr->next;
                ptr1 = ptr1->next;
            }
            while (sumptr != NULL)
            {
                int sum = sumptr->data + carry;
                carry = sum / 10;
                sumptr->data = sum % 10;
                if (sumptr->next == NULL && carry != 0)
                {
                    struct Node *newNode = new Node(carry);
                    sumptr->next = newNode;
                    break;
                }
                sumptr = sumptr->next;
            }
            reverseList(ptr2, second, carry);
            return second;
        }
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;

        cin >> n;
        Node *first = buildList(n);

        cin >> m;
        Node *second = buildList(m);
        Solution ob;
        Node *res = ob.addTwoLists(first, second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends