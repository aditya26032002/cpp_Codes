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

    node *recursiveReverse(node *head, node *prev, node *curr)
    {
        if (curr == NULL)
        {
            return prev;
        }
        node *forward = curr->next;
        curr->next = prev;
        curr->prev = forward;
        recursiveReverse(head, curr, forward);
    }
    node *reverse(node *head)
    {
        node *curr = head;
        node *prev = NULL;
        return recursiveReverse(head, prev, curr);
    }
};

int main()
{
    node *head = new node(1);
    node *tail = head;
    for (int i = 2; i < 6; i++)
    {
        head->insertAtTail(tail, i);
    }
    head->traverse();
    head = head->reverse(head);
    head->traverse();
    return 0;
}