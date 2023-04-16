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
    void getData()
    {
        cout << "Node data : " << this->data << endl;
        if (this->next != NULL)
        {
            cout << "Node next data: " << this->next->data << endl;
            cout << "Node prev data: " << this->prev->data << endl;
        }
    }
    void traverse(node *head, node *tail)
    {
        node *ptr = head;
        while (1)
        {
            cout << ptr->data << " ";
            ptr = ptr->next;
            if (ptr == head)
                break;
        }
        cout << endl;
    }
    void insertAtHead(node *&head, node *&tail, int data)
    {
        node *newHead = new node(data);
        newHead->next = head;
        head->prev = newHead;
        newHead->prev = tail;
        tail->next = newHead;
        head = newHead;
    }
    void insertAtTail(node *&head, node *&tail, int data)
    {
        node *newTail = new node(data);
        tail->next = newTail;
        newTail->prev = tail;
        newTail->next = head;
        head->prev = newTail;
        tail = newTail;
    }
    void insertAtPosition(node *&head, node *&tail, int position, int data)
    {
        if (position == 1)
        {
            head->insertAtHead(head, tail, data);
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
            tail->insertAtTail(head, tail, data);
            return;
        }
        node *newNode = new node(data);
        ptr2->next = newNode;
        newNode->prev = ptr2;
        newNode->next = ptr;
        ptr->prev = newNode;
    }
    void deleteHead(node *&head, node *&tail)
    {
        node *ptr = head;
        head = head->next;
        head->prev = tail;
        tail->next = head;
        delete ptr;
    }
    void deleteTail(node *&head, node *&tail)
    {
        node *ptr = tail;
        tail = tail->prev;
        tail->next = head;
        head->prev = tail;
        delete ptr;
    }
    void deleteAtPosition(node *&head, node *&tail, int position)
    {
        if (position == 1)
        {
            head->deleteHead(head, tail);
            return;
        }
        node *ptr = head;
        for (int i = 1; i < position; i++)
        {
            ptr = ptr->next;
        }
        if (ptr == tail)
        {
            tail->deleteTail(head, tail);
            return;
        }
        ptr->next->prev = ptr->prev;
        ptr->prev->next = ptr->next;
        delete ptr;
    }
};

int main()
{
    node *head = new node(1);
    node *tail = head;
    for (int i = 0; i < 5; i++)
    {
        int data;
        cout << "Input data : ";
        cin >> data;
        tail->insertAtTail(head, tail, data);
    }
    // head->insertAtHead(head, tail, 7);
    // head->insertAtTail(head, tail, 7);
    // head->insertAtPosition(head, tail, 7, 7);
    // head->deleteHead(head, tail);
    // head->deleteTail(head, tail);
    // head->deleteAtPosition(head, tail, 6);
    head->traverse(head, tail);
    cout << "Head : " << endl;
    head->getData();
    cout << "Tail : " << endl;
    tail->getData();
    return 0;
}