#include <iostream>
using namespace std;

int main()
{
    int n = 5;
    // cin >> n;

    for (int row = 1; row <= n; row++)
    {
        if (row <= (n / 2 + 1))
        {
            for (int col = 1; col <= (n / 2 + 1); col++)
            {
                if(col <= (n/2 + 1 - row))
                    cout << "\t";
                else
                    cout<<"*\t";
            }
            for (int col = 1; col <= (row - 1); col++)
            {
                cout << "*\t";
            }
            cout << endl;
        }
        else
        {
            int col = 1;
            for (col; col <= (n / 2 + 1); col++)
            {
                if (col <= (row - (n / 2 + 1)))
                {
                    cout << "\t";
                }
                else
                {
                    cout << "*\t";
                }
            }
            for (col = 1; col <= (n - row); col++)
            {
                cout << "*\t";
            }
            cout << endl;
        }
    }
}