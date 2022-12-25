#include <iostream>
using namespace std;

int main()
{
    int n = 4;
    for (int i = n; i >= 1; i--)
    {
        int count = n;
        for (int j = 1; j <= (2 * n - 1); j++)
        {
            if ((count > i) && (j <= (n - i)))
            {
                cout << count << " ";
                count--;
            }
            else if (j < ((2 * n - 1) - (n - i)))
                cout << count << " ";
            else
            {
                cout << count << " ";
                count++;
            }
        }
        cout << endl;
    }
    for (int i = 2; i <= n; i++)
    {
        int count = n;
        for (int j = 1; j <= (2 * n - 1); j++)
        {
            if ((count > i) && (j <= (n - i)))
            {
                cout << count << " ";
                count--;
            }
            else if (j < ((2 * n - 1) - (n - i)))
                cout << count << " ";
            else
            {
                cout << count << " ";
                count++;
            }
        }
        cout << endl;
    }
    return 0;
}