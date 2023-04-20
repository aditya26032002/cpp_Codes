#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    // Constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node *insertAtEnd(int data)
    {
        Node *newTail = new Node(data);
        this->next = newTail;
        return newTail;
    }
    Node *removeDuplicates(Node *head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        Node *next = head->next, *prev = head;
        while (next != NULL)
        {
            if (next->data == prev->data)
            {
                while (1)
                {
                    if (next->data != prev->data)
                    {
                        prev->next = next;
                        break;
                    }
                    if (next->next == NULL)
                    {
                        prev->next = NULL;
                        break;
                    }
                    if (next->data == prev->data)
                        next = next->next;
                }
            }
            prev = next;
            next = next->next;
        }
        return head;
    }
};

int main()
{
    int numOfNodes = 0;
    cout << "Enter number of nodes : ";
    cin >> numOfNodes;
    int data;
    cout << "Input data of head : ";
    cin >> data;
    Node *head = new Node(data);
    Node *tail = head;

    for (int i = 2; i <= numOfNodes; i++)
    {
        cout << "Input data : ";
        cin >> data;
        tail = tail->insertAtEnd(data);
    }

    head->removeDuplicates(head);
    Node *ptr = head;
    while (true)
    {
        cout << ptr->data;
        if (ptr->next == NULL)
            break;
        ptr = ptr->next;
        cout << "->";
    }

    return 0;
}