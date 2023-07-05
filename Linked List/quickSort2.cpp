#include <bits/stdc++.h>
using namespace std;

// Not done, gives TLE in GFG

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

    Node *partition(Node *head, Node *tail)
    {
        int count = 0;
        Node *ptr = head->next;
        while (1)
        {
            if (ptr->data < head->data)
                count++;
            if (ptr == tail)
                break;
            ptr = ptr->next;
        }
        if (count == 0)
            return head;
        ptr = head;
        while (count--)
        {
            ptr = ptr->next;
        }
        swap(ptr->data, head->data);

        Node *pt1 = head, *pt2 = ptr->next;
        while (pt1 != ptr && pt2 != tail->next)
        {
            while (pt1 != ptr && pt1->data < ptr->data)
            {
                pt1 = pt1->next;
            }
            while (pt2 != tail->next && pt2->data > ptr->data)
            {
                pt2 = pt2->next;
            }
            if (pt1 != ptr && pt2 != tail->next)
            {
                swap(pt1->data, pt2->data);
            }
        }
        return ptr;
    }

    void sort(Node *head, Node *tail)
    {
        if (head == NULL || head == tail)
            return;

        Node *p = partition(head, tail);
        sort(head, p);
        sort(p->next, tail);
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

    head->sort(head, tail);
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