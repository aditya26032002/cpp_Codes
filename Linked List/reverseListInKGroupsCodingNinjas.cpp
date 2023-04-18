#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
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

    Node *reverse(Node *prev, Node *&curr, int k)
    {
        if (k == 0 || curr == NULL)
        {
            return prev;
        }
        Node *forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        reverse(prev, curr, k - 1);
    }

    Node *solve(Node *head, Node *&curr, int k)
    {
        if (curr == NULL)
            return NULL;
        Node *newHead = reverse(NULL, curr, k);
        head->next = solve(curr, curr, k);
        return newHead;
    }

    Node *kReverse(Node *head, int k)
    {
        Node *curr = head;
        return solve(head, curr, k);
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

    head = head->kReverse(head, 2);
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