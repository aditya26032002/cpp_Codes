#include <bits/stdc++.h>
using namespace std;

class node
{
    int data;
    node *next;

public:
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    void getData()
    {
        cout << "Node data : " << this->data << endl;
        cout << "Node's next data : " << this->next->data << endl;
    }
    void traverse(node *head, node *tail)
    {
        node *ptr = head;
        while (1)
        {
            cout << ptr->data << " ";
            if (ptr->next == head)
                break;
            ptr = ptr->next;
        }
        cout << endl;
    }
    void insertAtHead(node *&head, node *tail, int data)
    {
        node *newHead = new node(data);
        tail->next = newHead;
        newHead->next = head;
        head = newHead;
    }
    void insertAtTail(node *head, node *&tail, int data)
    {
        node *newTail = new node(data);
        newTail->next = head;
        tail->next = newTail;
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
        for (int i = 1; i < position - 1; i++)
        {
            ptr = ptr->next;
        }
        if (ptr == tail)
        {
            tail->insertAtTail(head, tail, data);
            return;
        }
        node *newNode = new node(data);
        newNode->next = ptr->next;
        ptr->next = newNode;
    }
    void deleteHead(node *&head, node *&tail)
    {
        node *ptr = head;
        head = head->next;
        tail->next = head;
        delete ptr;
    }
    void deleteTail(node *&head, node *&tail)
    {
        node *ptr = head;
        node *ptr2 = tail;
        while (ptr->next != tail)
        {
            ptr = ptr->next;
        }
        ptr->next = head;
        tail = ptr;
        delete ptr2;
    }
    void deleteAtPosition(node *&head, node *&tail, int position)
    {
        if (position == 1)
        {
            head->deleteHead(head, tail);
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
            tail->deleteTail(head, tail);
            return;
        }
        ptr2->next = ptr->next;
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
    // head->insertAtHead(head, tail, 55);
    // head->insertAtTail(head, tail, 95);
    // head->insertAtPosition(head, tail, 7, 55);
    // head->deleteHead(head, tail);
    // head->deleteTail(head, tail);
    head->deleteAtPosition(head, tail, 6);
    head->traverse(head, tail);
    cout << "Head : " << endl;
    head->getData();
    cout << "Tail : " << endl;
    tail->getData();
    return 0;
}