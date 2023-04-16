#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    // Constructor
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
    Node *insertAtHead(int data)
    {
        Node *newHead = new Node(data);
        newHead->next = this;
        return newHead;
    }
    Node *inertAtPosition(int position, int data)
    {
        if (position == 1)
        {
            return this->insertAtHead(data);
        }
        Node *temp = this;
        for (int i = 0; i < position; i++)
        {
            temp = temp->next;
            if (temp->next == NULL)
                return insertAtEnd(data);
        }
        Node *newNode = new Node(data);
        newNode->next = temp->next;
        temp->next = newNode;
        return this;
    }
    Node *deleteHead()
    {
        Node *newHead = this->next;
        delete this;
        return newHead;
    }
    Node *deleteTail()
    {
        Node *newTail;
        Node *ptr = this;
        while (ptr->next != NULL)
        {
            newTail = ptr;
            ptr = ptr->next;
        }
        delete ptr;
        newTail->next = NULL;
        return newTail;
    }
    Node *deleteAtPosition(int position)
    {
        if (position == 1)
            return deleteHead();
        Node *ptr = this;
        Node *ptr2 = this;
        for (int i = 1; i < position; i++)
        {
            ptr2 = ptr;
            ptr = ptr->next;
        }
        ptr2->next = ptr->next;
    }
    Node *reverseList(Node *head)
    {
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

    // head = head->insertAtHead(5);
    // head = head->inertAtPosition(1, 10);
    // tail = tail->insertAtEnd(5);

    // head = head->deleteAtPosition(1);
    // head = head->deleteHead();
    // tail = head->deleteTail();
    head = head->reverseList(head);
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