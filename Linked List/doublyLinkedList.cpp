#include <bits/stdc++.h>
using namespace std;

class node
{
    int data;
    node *prev;
    node *next;

public:
    node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
    int getData()
    {
        return this->data;
    }
    void traverse()
    {
        node *ptr = this;
        while (ptr != NULL)
        {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }
    void insertAtTail(node *&tail, int data)
    {
        node *newTail = new node(data);
        tail->next = newTail;
        newTail->prev = tail;
        tail = newTail;
    }
    node *insertAtHead(int data)
    {
        node *newHead = new node(data);
        newHead->next = this;
        this->prev = newHead;
        return newHead;
    }
    void insertAtPosition(node *&head, node *&tail, int data, int position)
    {
        if (position == 1)
        {
            head = head->insertAtHead(data);
            return;
        }
        node *ptr = this;
        node *newNode = new node(data);
        for (int i = 1; i < position - 1; i++)
        {
            ptr = ptr->next;
        }
        if (ptr == tail)
        {
            tail->insertAtTail(tail, data);
            return;
        }
        newNode->next = ptr->next;
        newNode->prev = ptr;
        ptr->next = newNode;
    }
    void deleteHead(node *&head)
    {
        node *ptr = head;
        head = ptr->next;
        delete ptr;
    }
    void deleteTail(node *&tail)
    {
        node *ptr = tail;
        tail = tail->prev;
        tail->next = NULL;
        delete ptr;
    }
    void deleteAtPosition(node *&head, node *&tail, int position)
    {
        if (position == 1)
        {
            head->deleteHead(head);
            return;
        }
        node *ptr = head;
        node *ptr2;
        for (int i = 1; i < position; i++)
        {
            ptr2 = ptr;
            ptr = ptr->next;
        }
        if (ptr == tail)
        {
            tail->deleteTail(tail);
            return;
        }
        ptr2->next = ptr->next;
        ptr->next->prev = ptr2;
        delete ptr;
    }
};

int main()
{
    // node n1 = 5;
    // cout << n1.getData();
    node *head = new node(5);
    node *tail = head;
    // cout << head->getData();
    for (int i = 0; i < 4; i++)
    {
        int data;
        cout << "Input data: ";
        cin >> data;
        head->insertAtTail(tail, data);
    }
    // head = head->insertAtHead(-99);
    // head->insertAtPosition(head, tail, 55, 1);
    // head->deleteHead(head);
    // head->deleteTail(tail);
    head->deleteAtPosition(head, tail, 3);
    head->traverse();
    cout << "Head = " << head->getData() << endl;
    cout << "Tail = " << tail->getData() << endl;
    return 0;
}