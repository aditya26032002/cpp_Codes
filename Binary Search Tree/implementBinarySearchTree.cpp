#include <bits/stdc++.h>
using namespace std;

class Node
{
    int data;
    Node *left;
    Node *right;

public:
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
    // Space : O(n), Time: O(n)
    Node *insertIntoBST(Node *root, int d)
    {
        if (root == NULL)
        {
            Node *n = new Node(d);
            return n;
        }

        if (d < root->data)
        {
            root->left = insertIntoBST(root->left, d);
        }
        else
        {
            root->right = insertIntoBST(root->right, d);
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

    void preorder(Node *root)
    {
        if (root == NULL)
        {
            return;
        }
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }

    void inorder(Node *root)
    {
        if (root == NULL)
        {
            return;
        }
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
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

    bool search(Node *root, int x)
    {
        if (root == NULL)
            return false;

        if (root->data == x)
            return true;

        if (x < root->data)
            return search(root->left, x);

        else
            return search(root->right, x);
    }

    int getMax(Node *root)
    {
        if (root == NULL)
            return -1;
        if (root->right == NULL)
            return root->data;
        return getMax(root->right);
    }

    int getMin(Node *root)
    {
        if (root == NULL)
            return -1;

        Node *temp = root;
        while (temp->left != NULL)
            temp = temp->left;
        return temp->data;
    }
};

int main()
{
    Node *root = NULL;
    root->constructBST(root);
    cout << "Level order traversal : " << endl;
    root->levelOrderTraversalBST(root);
    // cout << "Preorder traversal : " << endl;
    // root->preorder(root);

    cout << "Minimum data : " << root->getMin(root) << endl;
    cout << "Maximum data : " << root->getMax(root) << endl;
    return 0;
}