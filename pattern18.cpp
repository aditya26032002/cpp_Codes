#include<iostream>
using namespace std;

int main(){
    int row = 1;
    while (row <= 4)
    {
        int count = 1;
        int col = 1;
        // Spaces
        while (col <= (4 - row))
        {
            cout<<" ";
            col++;
        }
        // 1st triangle
        while (col <= 4)
        {
            cout<<count;
            count++;
            col++;
        }
        count -= 2;
        // 2nd triangle
        while (count > 0)
        {
            cout<<count;
            count--;
        }
        cout<<endl;
        row++;
    }
    
    return 0;
}