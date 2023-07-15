#include <bits/stdc++.h>
using namespace std;

class NStack
{
    int *arr;
    int *next;
    int *top;
    int freespace;

public:
    // Initialize your data structure.
    NStack(int N, int S)
    {
        arr = new int[S];
        next = new int[S];
        top = new int[N];
        for (int i = 0; i < S - 1; i++)
            next[i] = i + 1;
        next[S - 1] = -1;
        for (int i = 0; i < N; i++)
            top[i] = -1;
        freespace = 0;
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        if (freespace == -1)
            return false;

        int index = freespace;
        freespace = next[index];
        next[index] = top[m - 1];
        top[m - 1] = index;
        arr[index] = x;
        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        if (top[m - 1] == -1)
            return -1;

        int topElement = arr[top[m - 1]];
        int temp = freespace;
        freespace = top[m - 1];
        top[m - 1] = next[freespace];
        next[freespace] = temp;
        return topElement;
    }
};

int main()
{

    return 0;
}