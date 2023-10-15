#include<iostream>
using namespace std;

int main(){
    int n = 5;
    for (int row = 1; row <= n; row++)
    {
        for (int col = 1; col <= n; col++)
        {
            if((row + col == n+1)  || row == col)
                cout<<"*\t";
            else
                cout<<"\t";
        }
        cout<<endl;
    }
    
    return 0;
}