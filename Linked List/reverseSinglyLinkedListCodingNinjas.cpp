#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node *insertAtEnd(int data)
    {
        Node *newTail = new Node(data);
        this->next = newTail;
        return newTail;
    }
    Node *reverseList(Node *head)
    {
        if (head == NULL)
            return head;
        Node *p1 = head;
        if (p1->next == NULL)
            return head;
        Node *p2 = p1->next;
        if (p2->next == NULL)
        {
            p1->next = NULL;
            p2->next = p1;
            return p2;
        }
        Node *p3 = p2->next;
        p1->next = NULL;
        while (1)
        {
            p2->next = p1;
            p1 = p2;
            p2 = p3;
            p3 = p3->next;
            if (p3 == NULL)
            {
                p2->next = p1;
                break;
            }
        }
        return p2;
    }

    Node *reverse(Node *head, Node *curr, Node *prev)
    {
        if (curr == NULL)
        {
            head = prev;
            return head;
        }
        Node *forward = curr->next;
        curr->next = prev;
        reverse(head, forward, curr);
    }

    Node *recursiveSol(Node *head)
    {
        Node *curr = head;
        Node *prev = NULL;
        return reverse(head, curr, prev);
    }
    Node *recursiveReverse2(Node *head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        Node *chhotaHead = head->recursiveReverse2(head->next);
        head->next->next = head;
        head->next = NULL;
        return chhotaHead;
    }
};

int main()
{
    int numOfNodes = 0;
    cout << "Enter number of nodes : ";
    cin >> numOfNodes;
    int data;
    cout << "Input data of head : ";
    cin >> data;
    Node *head = new Node(data);
    Node *tail = head;

    for (int i = 2; i <= numOfNodes; i++)
    {
        cout << "Input data : ";
        cin >> data;
        tail = tail->insertAtEnd(data);
    }
    // head = head->reverseList(head);
    // head = head->recursiveSol(head);
    head = head->recursiveReverse2(head);
    Node *ptr = head;
    while (true)
    {
        cout << ptr->data;
        if (ptr->next == NULL)
            break;
        ptr = ptr->next;
        cout << "->";
    }

    return 0;
}