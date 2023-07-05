#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }

    void insertAtEnd(Node *&tail, int x)
    {
        Node *newNode = new Node(x);
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    void deleteAtEnd(Node *&tail)
    {
        Node *temp = tail;
        tail = tail->prev;
        tail->next = NULL;
        delete temp;
    }
};

class Stack
{
public:
    Node *tail;
    int size = 0;

    void push(int x)
    {
        if (tail == NULL)
        {
            tail = new Node(x);
        }
        else
        {
            tail->insertAtEnd(tail, x);
        }
        size++;
    }

    void pop()
    {
        if (size == 0)
            cout << "Stack underflow!!" << endl;
        else
        {
            tail->deleteAtEnd(tail);
            size--;
        }
    }

    int peek()
    {
        if (size != 0)
            return tail->data;
        else
        {
            cout << "Stack is empty!!" << endl;
            return -1;
        }
    }
};

int main()
{
    Stack st;
    st.push(5);
    cout << st.peek() << endl;
    st.pop();
    cout << st.peek() << endl;
    st.push(6);
    cout << st.peek() << endl;
    st.push(7);
    cout << st.peek() << endl;
    return 0;
}