#include <bits/stdc++.h>
using namespace std;

class integers
{
private:
    void sayHello()
    {
        cout << "Hello" << endl;
    }

public:
    int a;

    integers(int a)
    {
        this->a = a;
    }
    int operator+(integers x)
    {
        return a - x.a;
    }
    void saySomething()
    {
        sayHello();
    }
};

int main()
{
    integers x1(5);
    integers x2(10);
    integers x3 = x1 + x2;
    cout << x3.a;

    // Abstraction
    x3.saySomething();
    return 0;
}