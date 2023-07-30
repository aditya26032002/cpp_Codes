#include <bits/stdc++.h>
using namespace std;

class Deque
{
    int *arr;
    int front, rear;
    int arrSize;

public:
    // Initialize your data structure.
    Deque(int n)
    {
        // Write your code here.
        arr = new int[n];
        front = -1;
        rear = -1;
        arrSize = n;
    }

    // Pushes 'X' in the front of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushFront(int x)
    {
        if (isFull())
            return false;
        if (front == -1)
            front = rear = arrSize / 2;
        else if (front == 0)
        {
            if (rear == arrSize - 1)
                return false;
            front = arrSize - 1;
        }
        else
            front--;
        arr[front] = x;
        return true;
    }

    // Pushes 'X' in the back of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushRear(int x)
    {
        if (isFull())
            return false;
        if (rear == -1)
            rear = front = arrSize / 2;
        else if (rear == arrSize - 1)
        {
            if (front == 0)
                return false;
            rear = 0;
        }
        else
            rear++;
        arr[rear] = x;
        return true;
    }

    // Pops an element from the front of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popFront()
    {
        // Write your code here.
        if (isEmpty())
            return -1;
        int element = arr[front];
        if (front == rear)
            front = rear = -1;
        else if (front == arrSize - 1)
            front = 0;
        else
            front++;
        return element;
    }

    // Pops an element from the back of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popRear()
    {
        if (isEmpty())
            return -1;
        int element = arr[rear];
        if (front == rear)
            front = rear = -1;
        else if (rear == 0)
            rear = arrSize - 1;
        else
            rear--;
        return element;
    }

    // Returns the first element of the deque. If the deque is empty, it returns -1.
    int getFront()
    {
        if (front == -1)
            return -1;
        return arr[front];
    }

    // Returns the last element of the deque. If the deque is empty, it returns -1.
    int getRear()
    {
        if (rear == -1)
            return -1;
        return arr[rear];
    }

    // Returns true if the deque is empty. Otherwise returns false.
    bool isEmpty()
    {
        if (front == -1)
            return true;
        return false;
    }

    // Returns true if the deque is full. Otherwise returns false.
    bool isFull()
    {
        if ((front == 0 && rear == arrSize - 1) || ((front - 1) == rear))
            return true;
        return false;
    }
};

int main()
{

    return 0;
}