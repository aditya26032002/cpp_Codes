#include<iostream>
using namespace std;

int main(){
    int row = 1;
    while (row <= 4)
    {
        int col = 1;
        while (col <= (4 - row))
        {
            cout<<" ";
            col++;
        }
        while (col <= 4)
        {
            cout<<row;
            col++;
        }
        cout<<endl;
        row++;
    }
    
    return 0;
}