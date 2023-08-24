#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode *buildBSTFromList(ListNode *head, ListNode *tail)
    {
        if (head == NULL && tail == NULL)
            return NULL;

        ListNode *slow = head, *fast = head, *prev = NULL;

        while (fast != NULL && fast->next != NULL)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        TreeNode *root = new TreeNode(slow->val);
        if (prev != NULL)
        {
            prev->next = NULL;
            root->left = buildBSTFromList(head, prev);
        }
        if (slow->next != NULL)
        {
            root->right = buildBSTFromList(slow->next, tail);
        }
        return root;
    }

    TreeNode *sortedListToBST(ListNode *head)
    {
        if (head == NULL)
            return NULL;

        ListNode *tail = head;
        while (tail->next != NULL)
            tail = tail->next;

        return buildBSTFromList(head, tail);
    }
};

int main()
{

    return 0;
}