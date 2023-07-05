#include <bits/stdc++.h>
using namespace std;

class Stack
{
public:
    int s[50];
    int TopIndex = -1;

    void push(int x)
    {
        if (TopIndex == 49)
        {
            cout << "Stack overflow!" << endl;
            return;
        }
        TopIndex++;
        s[TopIndex] = x;
    }

    void pop()
    {
        if (TopIndex == -1)
        {
            cout << "Stack underflow!" << endl;
            return;
        }
        s[TopIndex] = -1;
        TopIndex--;
    }

    int top()
    {
        if (TopIndex == -1)
        {
            cout << "Stack is empty!" << endl;
            return INT_MIN;
        }
        else
            return s[TopIndex];
    }

    int size()
    {
        return TopIndex + 1;
    }

    bool empty()
    {
        if (TopIndex == -1)
            return true;
        else
            return false;
    }
};

int main()
{
    stack<int> s;
    Stack st;

    st.push(5);
    st.push(6);
    st.pop();
    cout << st.top() << endl;
    cout << st.size() << endl;
    return 0;
}