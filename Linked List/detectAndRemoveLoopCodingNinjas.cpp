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
    void insertAtTail(node *head, node *&tail, int data)
    {
        node *newTail = new node(data);
        newTail->next = head;
        tail->next = newTail;
        tail = newTail;
    }
    node *removeLoop(node *head)
    {
        node *prevOfFast;
        node *fast = head, *slow = head;
        while (fast->next->next != NULL)
        {
            prevOfFast = fast->next;
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
            {
                if (fast != head)
                {
                    slow = head;
                    while (slow != fast)
                    {
                        prevOfFast = fast;
                        slow = slow->next;
                        fast = fast->next;
                    }
                }
                prevOfFast->next = NULL;
                break;
            }
        }
        return head;
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
    head->removeLoop(head);
    head->traverse(head, tail);
    return 0;
}