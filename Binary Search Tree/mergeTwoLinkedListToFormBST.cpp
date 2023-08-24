#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int x)
    {
        this->data = x;
        this->left = NULL;
        this->right = NULL;
    }
    // Space: O(1), Time: O(n)
    Node *insertBST(Node *root, int x)
    {
        if (root == NULL)
        {
            root = new Node(x);
            return root;
        }
        Node *ptr = root;
        while (true)
        {
            if (x < ptr->data)
            {
                if (ptr->left != NULL)
                {
                    ptr = ptr->left;
                }
                else
                {
                    Node *n = new Node(x);
                    ptr->left = n;
                    return root;
                }
            }
            else
            {
                if (ptr->right != NULL)
                {
                    ptr = ptr->right;
                }
                else
                {
                    Node *n = new Node(x);
                    ptr->right = n;
                    return root;
                }
            }
        }
        return root;
    }

    void constructBST(Node *&root)
    {
        cout << "Input datas : " << endl
             << "Type -1 to end inserting data's." << endl;

        int d;
        cin >> d;
        while (d != -1)
        {
            root = insertBST(root, d);
            cin >> d;
        }
    }

    void levelOrderTraversalBST(Node *root)
    {
        queue<Node *> q;
        q.push(root);
        q.push(NULL);
        while (q.size() != 1)
        {
            if (q.front() == NULL)
            {
                q.pop();
                q.push(NULL);
                cout << endl;
            }
            else
            {
                Node *temp = q.front();
                q.pop();

                cout << temp->data << " ";
                if (temp->left != NULL)
                {
                    q.push(temp->left);
                }
                if (temp->right != NULL)
                {
                    q.push(temp->right);
                }
            }
        }
        cout << endl;
    }
    pair<Node *, Node *> flatten(Node *root)
    {
        if (root == NULL)
            return {NULL, NULL};

        Node *leftNode = NULL;
        Node *rightNode = NULL;

        pair<Node *, Node *> lft = flatten(root->left);
        pair<Node *, Node *> rght = flatten(root->right);

        root->left = NULL;
        root->right = rght.first;
        if (lft.first != NULL)
        {
            lft.second->right = root;
            leftNode = lft.first;
        }
        else
            leftNode = root;

        if (rght.second != NULL)
            rightNode = rght.second;
        else
            rightNode = root;

        return {leftNode, rightNode};
    }

    Node *mergeTwoSortedLinkedList(Node *root1, Node *root2)
    {
        Node *newRoot = NULL;
        Node *ptr = NULL;
        while (root1 != NULL && root2 != NULL)
        {
            if (root1->data < root2->data)
            {
                if (newRoot == NULL)
                {
                    newRoot = root1;
                    ptr = newRoot;
                }
                else
                {
                    ptr->right = root1;
                    ptr = root1;
                }
                root1 = root1->right;
            }
            else
            {
                if (newRoot == NULL)
                {
                    newRoot = root2;
                    ptr = newRoot;
                }
                else
                {
                    ptr->right = root2;
                    ptr = root2;
                }
                root2 = root2->right;
            }
        }
        while (root1 != NULL)
        {

            ptr->right = root1;
            ptr = root1;
            root1 = root1->right;
        }
        while (root2 != NULL)
        {

            ptr->right = root2;
            ptr = root2;
            root2 = root2->right;
        }
        return newRoot;
    }

    void convertIntoDoublyLinkedList(Node *root)
    {
        Node *ptr = root;
        while (ptr->right != NULL)
        {
            ptr->right->left = ptr;
            ptr = ptr->right;
        }
    }

    Node *buildBSTFromDoublyList(Node *head, Node *tail)
    {
        if (head == NULL && tail == NULL)
            return NULL;

        Node *slow = head, *fast = head->right;
        while (fast != NULL && fast->right != NULL)
        {
            slow = slow->right;
            fast = fast->right->right;
        }
        Node *root = slow;
        if (root->left != NULL)
        {
            root->left->right = NULL;
            root->left = buildBSTFromDoublyList(head, root->left);
        }
        if (root->right != NULL)
        {
            root->right->left = NULL;
            root->right = buildBSTFromDoublyList(root->right, tail);
        }

        return root;
    }

    Node *mergeTwoBST(Node *root1, Node *root2)
    {
        root1 = (flatten(root1)).first;
        root2 = (flatten(root2)).first;

        Node *mergedListRoot = mergeTwoSortedLinkedList(root1, root2);

        convertIntoDoublyLinkedList(mergedListRoot);

        printlist(mergedListRoot);
        cout << endl;

        Node *tail = mergedListRoot;
        while (tail->right != NULL)
            tail = tail->right;

        Node *finalBSTroot = buildBSTFromDoublyList(mergedListRoot, tail);
        return finalBSTroot;
    }

    void printlist(Node *root)
    {
        while (root != NULL)
        {
            cout << root->data << " ";
            root = root->right;
        }
        cout << endl;
    }
};

int main()
{
    Node *root1 = NULL, *root2 = NULL;
    cout << "Contruct BST1" << endl;
    root1->constructBST(root1);
    cout << "Contruct BST2" << endl;
    root2->constructBST(root2);

    Node *mergedBSTroot = root1->mergeTwoBST(root1, root2);

    cout << "Level ordered traversal of BST\n";
    mergedBSTroot->levelOrderTraversalBST(mergedBSTroot);
    return 0;
}

/*
5
3
6
2
4
-1
2
1
3
7
6
-1
*/