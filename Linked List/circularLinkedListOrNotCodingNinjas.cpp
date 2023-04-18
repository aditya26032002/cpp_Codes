#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    void insertAtTail(node *head, node *&tail, int data)
    {
        node *newTail = new node(data);
        newTail->next = head;
        tail->next = newTail;
        tail = newTail;
    }
    bool isCircular(node *head)
    {
        if (head == NULL || head->next == NULL)
            return false;
        node *ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
            if (ptr == head)
                return true;
        }
        return false;
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
    tail->next = NULL;

    return 0;
}