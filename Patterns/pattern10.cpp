#include<iostream>
using namespace std;

int main(){
    int row = 1;
    char ch = 'A' + 4 - 1;
    while (row <= 4)
    {
        int col = 1;
        while (col <= row)
        {
            cout<<ch;
            col++;
            ch++;
        }
        cout<<endl;
        ch = ch - row - 1;
        row++;
    }
    // while (row <= 4)
    // {
    //     int col = 1;
    //     char ch = 'A' + 4 - row;
    //     while (col <= row)
    //     {
    //         cout<<ch;
    //         col++;
    //         ch++;
    //     }
    //     row++;
    //     cout<<endl;
    // }
    return 0;
}