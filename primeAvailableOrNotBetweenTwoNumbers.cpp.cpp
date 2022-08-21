#include <iostream>
using namespace std;

bool primeOrNot(int x)
{
    if (x == 1)
    {
        return false;
    }

    for (int i = x - 1; i >= 2; i--)
    {
        if (x % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n, m;
    cin >> n >> m;
    int i = n + 1;
    for (i; i <= m; i++)
    {
        if(primeOrNot(i)){
            cout<<"Found a value less than m i.e prime : "<<i;
            break;
        }
    }

    return 0;
}