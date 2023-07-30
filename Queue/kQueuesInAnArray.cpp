#include <bits/stdc++.h>
using namespace std;

class Queue
{
public:
    int *arr, *next, *front, *rear, *size;
    int k, n, freespot;

    Queue(int N, int K)
    {
        n = N;
        k = K;
        freespot = 0;
        arr = new int[n];
        next = new int[n];
        front = new int[k];
        rear = new int[k];
        size = new int[k];
        for (int i = 0; i < n; i++)
            next[i] = i + 1;
        next[n - 1] = -1;
        for (int i = 0; i < k; i++)
        {
            front[i] = rear[i] = -1;
            size[i] = 0;
        }
    }

    bool push(int x, int i)
    {
        if (freespot == -1)
            return false;

        int index = freespot;
        freespot = next[index];
        if (front[i - 1] == -1)
            front[i - 1] = index;
        else
            next[rear[i - 1]] = index;

        next[index] = -1;
        rear[i - 1] = index;
        arr[index] = x;
        size[i - 1]++;
        return true;
    }

    bool pop(int i)
    {
        if (front[i - 1] == -1)
            return false;

        int index = front[i - 1];
        if (front[i - 1] == rear[i - 1])
            rear[i - 1] = -1;
        front[i - 1] = next[index];
        next[index] = freespot;
        freespot = index;
        size[i - 1]--;
        return true;
    }

    int getFront(int i)
    {
        if (size[i - 1] == 0)
            return -1;
        return arr[front[i - 1]];
    }

    // int getRear(int i)
    // {
    //     if (size[i - 1] == 0)
    //         return -1;
    //     return arr[rear[i - 1]];
    // }

    int getSize(int i)
    {
        return size[i - 1];
    }
};

int main()
{
    int n, k;
    cin >> n >> k;
    Queue que(n, k);

    int queries;
    cin >> queries;
    while (queries--)
    {
        int i;
        cin >> i;
        // push
        if (i == 1)
        {
            int x, q;
            cin >> x >> q;
            if (que.push(x, q))
                cout << "Pushed " << x << " to " << q << "th queue" << endl;
            else
                cout << "Queue is full" << endl;
        }
        // pop
        else if (i == 2)
        {
            int q;
            cin >> q;
            if (que.pop(q))
                cout << "Popped from " << q << "th queue" << endl;
            else
                cout << "Queue is empty, cant pop!" << endl;
        }
        // front
        else if (i == 3)
        {
            int q;
            cin >> q;
            int element = que.getFront(q);
            if (element == -1)
                cout << "Queue " << q << " is empty!" << endl;
            else
                cout << element << endl;
        }
        // size
        else if (i == 4)
        {
            int q;
            cin >> q;
            cout << "Queue " << q << " has size of " << que.getSize(q) << endl;
        }
    }
    return 0;
}