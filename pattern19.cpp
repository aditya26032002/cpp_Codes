#include<iostream>
using namespace std;

int main(){
    int row = 1;
    while(row <= 5){
        int col = 1;
        // 1st triangle - 1234
        while (col <= (5 - row + 1))
        {
            cout<<col<<" ";
            col++;
        }
        // 2nd triangle - ******
        int stars = 2 * row - 2;
        while (stars)
        {
            cout<<"* ";
            stars--;
        }
        // 3rd triangle - 4321
        col--;
        while (col)
        {
            cout<<col<<" ";
            col--;
        }
        cout<<endl;
        row++;
    }
    return 0;
}