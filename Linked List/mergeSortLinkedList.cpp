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

    Node *findMid(Node *head)
    {
        Node *slow = head, *fast = head->next;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    Node *mergeTwoSortedHalves(Node *left, Node *right)
    {
        if (left == NULL)
            return right;
        if (right == NULL)
            return left;

        Node *ans = new Node(-1);
        Node *ptr = ans;
        while (left != NULL && right != NULL)
        {
            if (left->data < right->data)
            {
                ptr->next = left;
                ptr = left;
                left = left->next;
            }
            else
            {
                ptr->next = right;
                ptr = right;
                right = right->next;
            }
        }
        while (left != NULL)
        {
            ptr->next = left;
            ptr = left;
            left = left->next;
        }
        while (right != NULL)
        {
            ptr->next = right;
            ptr = right;
            right = right->next;
        }
        ptr = ans;
        ans = ans->next;
        delete ptr;
        return ans;
    }

    Node *mergeSort(Node *head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        Node *mid = findMid(head);
        Node *left = head;
        Node *right = mid->next;
        mid->next = NULL;
        left = mergeSort(left);
        right = mergeSort(right);
        return mergeTwoSortedHalves(left, right);
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
    head = head->mergeSort(head);
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