#include<iostream>
using namespace std;

int main(){
    int n = 5;
    for(int row = 1; row <= n; row++){
        int col = 1;
        for(col; col <= n; col++){
            if( (row == 1) || (row == n) || (col == 1) || (col == n) )
                cout<<"*";
            else
                cout<<" ";
        }
        cout<<endl;
    }
    return 0;
}