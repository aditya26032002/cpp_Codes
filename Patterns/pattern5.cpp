#include<iostream>
using namespace std;

int main(){
    int row = 1;
    while (row <= 4)
    {
        int col = row;
        while (col > 0)
        {
            cout<<col;
            col--;
        }
        cout<<endl;
        row++;
    }
    
    return 0;
}