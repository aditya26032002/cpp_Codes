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

    Node *partition(Node *head)
    {
        int count = 0;
        Node *ptr = head->next;
        while (ptr != NULL)
        {
            if (ptr->data < head->data)
                count++;
            ptr = ptr->next;
        }
        if (count == 0)
            return head;
        Node *ans = new Node(-1);
        Node *temp = ans;
        ptr = head->next;
        head->next = NULL;
        while (ptr != NULL)
        {
            temp->next = ptr;
            temp = temp->next;
            ptr = ptr->next;
            if (count == 1)
            {
                temp->next = head;
                temp = temp->next;
            }
            count--;
        }

        Node *prevpt1 = ans, *pt1 = ans->next, *prevpt2 = head, *pt2 = head->next;
        while (pt1 != head && pt2 != NULL)
        {
            while (pt1 != head && pt1->data < head->data)
            {
                prevpt1 = pt1;
                pt1 = pt1->next;
            }
            while (pt2 != NULL && pt2->data > head->data)
            {
                prevpt2 = pt2;
                pt2 = pt2->next;
            }
            if (pt1 != head && pt2 != NULL)
            {
                prevpt1->next = pt2;
                prevpt2->next = pt1;
                Node *temp = pt1->next;
                pt1->next = pt2->next;
                pt2->next = temp;

                temp = pt2;
                pt2 = pt1;
                pt1 = temp;
            }
        }
        return ans->next;
    }

    Node *sort(Node *head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        Node *firsthead = partition(head);
        Node *secondPart = head->next;
        head->next = NULL;
        Node *first = sort(firsthead);
        Node *second = sort(secondPart);

        // Node *ptr = first;
        // while (ptr->next != NULL)
        // {
        //     ptr = ptr->next;
        // }
        head->next = second;

        return first;
    }

    Node *quickSort(Node *headRef)
    {
        if (headRef == NULL || headRef->next == NULL)
            return headRef;

        // headRef = sort(headRef);
        return sort(headRef);
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

    head = head->sort(head);
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