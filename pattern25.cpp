#include <iostream>
using namespace std;

int main()
{
    int n = 5;
    for (int row = 1; row <= n; row++)
    {
        if (row <= (n / 2 + 1))
        {
            for (int col = 1; col <= (n / 2 + 1 - row); col++)
            {
                cout << "\t";
            }
            cout << "*\t";
            for (int count = (row - 1)*2 - 1; count > 0; count--)
            {
                cout << "\t";
            }
            if (row != 1)
                cout << "*\t";
            cout << endl;
        }
        else{
            for(int col = 1; col <= (row - n/2 -1); col++){
                cout<<"\t";
            }
            cout<<"*\t";
            for(int count = (n-row)*2 - 1; count > 0; count--){
                cout<<"\t";
            }
            if(row != n)
                cout<<"*\t";
            cout<<endl;
        }
    }

    return 0;
}