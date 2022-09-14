#include<iostream>
using namespace std;

int main(){
    int n = 5;
    int row = 1;
    for(row; row <= n; row++){
        int col = 1;
        for(col; col <= row; col++){
            if((row + col) % 2 == 0)
                cout<<"1\t";
            else
                cout<<"0\t";
        }
        cout<<endl;
    }
    return 0;
}