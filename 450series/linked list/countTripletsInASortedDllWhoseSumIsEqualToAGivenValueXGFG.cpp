#include <bits/stdc++.h>
using namespace std;

// Not done

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
    void findTripletSum(node *head, int sum)
    {
        node *ptr1 = head;
        node *ptr2 = head;
        while (ptr2->next != NULL)
        {
            ptr2 = ptr2->next;
        }
        node *tail = ptr2;
        while (ptr1 != ptr2 && ptr1 != NULL && ptr2 != NULL)
        {
            if (ptr1->data + ptr2->data > sum)
            {
                while (ptr1 != ptr2 && ptr2 != NULL && ptr1->data + ptr2->data < sum)
                {
                    ptr2 = ptr2->prev;
                }
            }
            node *ptr3 = ptr1->next;
            while (ptr3 != ptr1 && ptr3 != ptr2)
            {
                int temSum = ptr1->data + ptr2->data + ptr3->data;
                if (temSum <= sum)
                {
                    while (ptr3 != ptr2 && ptr1->data + ptr2->data + ptr3->data <= sum)
                    {
                        if (ptr1->data + ptr2->data + ptr3->data == sum)
                        {
                            cout << ptr1->data << ", " << ptr3->data << ", " << ptr2->data << endl;
                            break;
                        }
                        ptr3 = ptr3->next;
                    }
                }
                else
                {
                    while (ptr3 != ptr1 && ptr1->data + ptr2->data + ptr3->data >= sum)
                    {
                        if (ptr1->data + ptr2->data + ptr3->data == sum)
                        {
                            cout << ptr1->data << ", " << ptr3->data << ", " << ptr2->data << endl;
                            break;
                        }
                        ptr3 = ptr3->prev;
                    }
                }
            }
            ptr1 = ptr1->next;
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
    head->findTripletSum(head, 17);
    return 0;
}