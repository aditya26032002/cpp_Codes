#include<iostream>
using namespace std;

int main(){
    int row = 1;
    while (row <= 4)
    {
        int col = 1;
        // int count = row;
        while (col <= row)
        {
            // cout<<count;
            // count++;
            cout<<col + row - 1;
            col++;
        }
        cout<<endl;
        row++;
    }
    
    return 0;
}