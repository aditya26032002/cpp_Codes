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
    void findPairSum(node *head, int sum)
    {
        node *ptr1 = head;
        node *ptr2 = head;
        while (ptr2->next != NULL)
        {
            ptr2 = ptr2->next;
        }
        while (ptr1 != ptr2 && ptr1 != NULL && ptr2 != NULL)
        {
            if (ptr1 != ptr2 && ptr1->data + ptr2->data >= sum)
            {
                while (ptr1 != ptr2 && ptr2 != NULL && ptr1->data + ptr2->data >= sum)
                {
                    if (ptr1->data + ptr2->data == sum)
                    {
                        cout << "{" << ptr1->data << ", " << ptr2->data << "}" << endl;
                        ptr2 = ptr2->prev;
                        break;
                    }
                    ptr2 = ptr2->prev;
                }
            }
            if (ptr1 != ptr2 && ptr1->data + ptr2->data < sum)
            {
                while (ptr1 != ptr2 && ptr1 != NULL && ptr1->data + ptr2->data <= sum)
                {
                    if (ptr1->data + ptr2->data == sum)
                    {
                        cout << "{" << ptr1->data << ", " << ptr2->data << "}" << endl;
                        ptr1 = ptr1->next;
                        break;
                    }
                    ptr1 = ptr1->next;
                }
            }
        }
    }
};

int main()
{
    node *head = new node(1);
    node *tail = head;
    for (int i = 0; i < 6; i++)
    {
        int data;
        cout << "Input data: ";
        cin >> data;
        head->insertAtTail(tail, data);
    }
    head->traverse();
    head->findPairSum(head, 10);
    return 0;
}