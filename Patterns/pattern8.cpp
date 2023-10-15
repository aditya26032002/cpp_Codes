#include<iostream>
using namespace std;

int main(){
    int row = 1;
    char ch = 'A';
    while (row <= 4)
    {
        int col = 1;
        while (col <= row)
        {
            cout<<ch;
            col++;
        }
        cout<<endl;
        row++;
        ch++;
    }
    
    return 0;
}