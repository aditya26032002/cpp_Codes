#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>

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
};

class Queue
{
public:
    node *head;
    node *tail;
    int size;

    Queue()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty()
    {
        if (size == 0)
            return true;
        return false;
    }

    void enqueue(int data)
    {
        if (isEmpty())
        {
            head = new node(data);
            tail = head;
            size++;
            return;
        }
        node *newNode = new node(data);
        tail->next = newNode;
        tail = newNode;
        size++;
    }

    int dequeue()
    {
        if (isEmpty())
            return -1;
        int frontData = head->data;
        node *temp = head;
        head = head->next;
        delete temp;
        if (size == 1)
            tail = NULL;
        size--;
        return frontData;
    }

    int front()
    {
        if (isEmpty())
            return -1;
        return head->data;
    }
};

int main()
{

    return 0;
}