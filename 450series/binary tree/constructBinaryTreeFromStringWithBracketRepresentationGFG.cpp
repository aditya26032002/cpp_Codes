#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};

class Solution
{
public:
    Node *build(string &str, int &i)
    {
        Node *root = NULL;
        if (str[i] >= '0' && str[i] <= '9')
        {
            string el = "";
            int j = i;
            while (true)
            {
                el += str[j];
                if (j + 1 < str.size() && (str[j + 1] >= '0' && str[j + 1] <= '9'))
                    j++;
                else
                    break;
            }
            int x = stoi(el);
            root = new Node(x);
            i = j + 1;
        }
        if (str[i] == '(')
        {
            i++;
            root->left = build(str, i);
            if (str[i] == '(')
            {
                i++;
                root->right = build(str, i);
            }
        }
        if (str[i] == ')')
        {
            i++;
            return root;
        }
        return root;
    }
    Node *treeFromString(string str)
    {
        int i = 0;
        return build(str, i);
    }
};

int main()
{

    return 0;
}