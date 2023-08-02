#include <bits/stdc++.h>
using namespace std;

class node
{
    int data;
    node *left, *right;

public:
    node(int x)
    {
        this->data = x;
        this->left = NULL;
        this->right = NULL;
    }

    void buildTree(node *&root)
    {
        int d;
        cout << "Enter data : ";
        cin >> d;
        if (d == -1)
            return;

        root = new node(d);

        cout << "For left of " << d << endl;
        buildTree(root->left);
        cout << "For right of " << d << endl;
        buildTree(root->right);
    }

    void traversal(node *root)
    {
        if (root == NULL)
            return;

        cout << root->data << " ";

        traversal(root->left);
        traversal(root->right);
    }

    void levelOrderTraversal(node *root)
    {
        queue<node *> q;
        q.push(root);
        q.push(NULL);

        while (!q.empty())
        {
            node *temp = q.front();
            q.pop();

            if (temp == NULL)
            {
                cout << endl;
                if (!q.empty())
                {
                    q.push(NULL);
                }
            }
            else
            {
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
    }

    /*
    void levelOrderTraversal(node *root)
    {
        queue<node *> q;
        queue<int> level;
        q.push(root);
        level.push(0);

        while (!q.empty())
        {
            int currLevel = level.front();
            node *temp = q.front();
            cout << temp->data << " ";
            q.pop();
            level.pop();
            if (level.empty() || level.front() != currLevel)
            {
                cout << endl;
            }

            if (temp->left != NULL)
            {
                q.push(temp->left);
                level.push(currLevel + 1);
            }

            if (temp->right != NULL)
            {
                q.push(temp->right);
                level.push(currLevel + 1);
            }
        }
    }
    */

    void reverseLevelOrderTraversal(node *root)
    {
        stack<queue<node *>> st;
        queue<node *> q;
        q.push(root);

        while (true)
        {
            st.push(q);
            int size = q.size();
            while (size--)
            {
                node *ptr = q.front();
                q.pop();
                if (ptr->left != NULL)
                {
                    q.push(ptr->left);
                }
                if (ptr->right != NULL)
                {
                    q.push(ptr->right);
                }
            }
            if (q.empty())
            {
                break;
            }
        }
        while (!st.empty())
        {
            queue<node *> temp = st.top();
            st.pop();
            while (!temp.empty())
            {
                cout << (temp.front())->data << " ";
                temp.pop();
            }
            cout << endl;
        }
    }

    /*
    void solve(queue<node *> q)
    {
        if (q.empty())
            return;

        queue<int> temp;
        queue<node *> que;
        cout << q.size() << endl;
        while (!q.empty())
        {
            node *ptr = q.front();
            q.pop();
            temp.push(ptr->data);
            if (ptr->left != NULL)
            {
                que.push(ptr->left);
            }
            if (ptr->right != NULL)
            {
                que.push(ptr->right);
            }
        }
        solve(que);
        while (!temp.empty())
        {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
    }
    void reverseLevelOrderTraversal(node *root)
    {
        queue<node *> q;
        q.push(root);
        solve(q);
    }
    */

    void inorder(node *root)
    {
        if (root == NULL)
            return;

        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

    void preorder(node *root)
    {
        if (root == NULL)
            return;

        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }

    void postorder(node *root)
    {
        if (root == NULL)
            return;

        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }

    void inorderIterative(node *root)
    {
        stack<node *> st;
        node *curr = root;
        while (!st.empty() || curr != NULL)
        {
            if (curr != NULL)
            {
                st.push(curr);
                curr = curr->left;
            }
            else
            {
                curr = st.top();
                st.pop();
                cout << curr->data << " ";
                curr = curr->right;
            }
        }
        cout << endl;
    }

    void preorderIterative(node *root)
    {
        stack<node *> st;
        st.push(root);
        while (!st.empty())
        {
            node *temp = st.top();
            cout << temp->data << " ";
            st.pop();
            if (temp->right != NULL)
                st.push(temp->right);
            if (temp->left != NULL)
                st.push(temp->left);
        }
        cout << endl;
    }

    // Not done
    void postorderIterative(node *root)
    {
        stack<node *> st;
        node *curr = root;
        while (curr != NULL)
        {
            if (curr == NULL)
            {
                curr = st.top();
                st.pop();
                if (curr->right != NULL && curr->right == st.top())
                {
                    node *temp = st.top();
                    st.pop();
                    st.push(curr);
                    curr = temp;
                }
                else
                {
                    cout << curr->data << " ";
                    curr = NULL;
                }
            }
            else
            {
                if (curr->right != NULL)
                {
                    st.push(curr->right);
                }
                st.push(curr);
                curr = curr->left;
            }
        }
        cout << endl;
    }

    /*
    void postorderIterative(node *root)
    {
        stack<node *> st;
        st.push(root);
        stack<int> op;
        while (!st.empty())
        {
            node *temp = st.top();
            st.pop();
            op.push(temp->data);

            if (temp->left != NULL)
            {
                st.push(temp->left);
            }
            if (temp->right != NULL)
            {
                st.push(temp->right);
            }
        }
        while (!op.empty())
        {
            cout << op.top() << " ";
            op.pop();
        }
        cout << endl;
    }
    */

    void levelOrderTreeBuild(node *&root)
    {
        queue<node *> q;
        int dt;
        cout << "Enter root data : " << endl;
        cin >> dt;
        root = new node(dt);
        q.push(root);
        while (!q.empty())
        {
            node *temp = q.front();
            q.pop();
            int leftData, rightData;
            cout << "Enter data for left of " << temp->data << " : " << endl;
            cin >> leftData;
            cout << "Enter data for right of " << temp->data << " : " << endl;
            cin >> rightData;
            if (leftData != -1)
            {
                temp->left = new node(leftData);
                q.push(temp->left);
            }
            if (rightData != -1)
            {
                temp->right = new node(rightData);
                q.push(temp->right);
            }
        }
    }
};

int main()
{
    node *root = NULL;
    // root->buildTree(root);
    root->levelOrderTreeBuild(root);
    // root->traversal(root);
    root->levelOrderTraversal(root);
    // root->reverseLevelOrderTraversal(root);

    // cout << "\nInorder : ";
    // root->inorder(root);
    // cout << "\nInorder iterative: ";
    // root->inorderIterative(root);

    // cout << "\nPreorder : ";
    // root->preorder(root);
    // cout << "\nPreorder iterative: ";
    // root->preorderIterative(root);

    // cout << "\nPost order : ";
    // root->postorder(root);
    // cout << "\nPost order iterative: ";
    // root->postorderIterative(root);
    return 0;
}

/*
1
2 3
4 5 6 7
-1 -1 -1 -1 -1 -1 -1 -1
*/

// 1 2 4 -1 -1 5 -1 -1 3 -1 -1
// 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1