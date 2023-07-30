#include <bits/stdc++.h>
using namespace std;

void interleave(queue<int> &q)
{
    queue<int> firstHalf;
    int size = q.size();
    for (int i = 0; i < size / 2; i++)
    {
        firstHalf.push(q.front());
        q.pop();
    }
    while (!firstHalf.empty())
    {
        q.push(firstHalf.front());
        firstHalf.pop();
        q.push(q.front());
        q.pop();
    }
    if (size % 2 != 0)
    {
        q.push(q.front());
        q.pop();
    }
}

int main()
{
    queue<int> q;
    int size;
    cin >> size;
    cout << "Enter elements." << endl;
    while (size--)
    {
        int x;
        cin >> x;
        q.push(x);
    }
    interleave(q);
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}