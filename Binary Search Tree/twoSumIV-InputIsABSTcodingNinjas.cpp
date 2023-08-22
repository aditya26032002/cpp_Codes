#include <bits/stdc++.h>
using namespace std;

template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;
};

/* // Time: O(n) Space: O(n)
void inorderTraverse(BinaryTreeNode<int> *root, vector<int> &v)
{
    if (root == NULL)
        return;

    inorderTraverse(root->left, v);
    v.push_back(root->data);
    inorderTraverse(root->right, v);
}

bool twoSumInBST(BinaryTreeNode<int> *root, int target)
{
    vector<int> v;
    inorderTraverse(root, v);

    int i = 0, j = v.size() - 1;
    while (i < j)
    {
        int sum = v[i] + v[j];
        if (sum == target)
            return true;

        if (sum < target)
            i++;
        else
            j--;
    }
    return false;
}
*/

int main()
{

    return 0;
}