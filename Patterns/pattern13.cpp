#include<iostream>
using namespace std;

int main(){
    int row = 1;
    while (row <= 4)
    {
        int col = 1;
        // Spaces
        while (col <= (row-1))
        {
            cout<<" ";
            col++;
        }
        // Stars
        while (col <= 4)
        {
            cout<<"*";
            col++;
        }
        cout<<endl;
        row++;
    }
    
    return 0;
}