#include <iostream>
using namespace std;

int main(){
    int n = 5;

    int row = 1;
    for(row; row <= n; row++){
        if(row <= (n/2 + 1)){
            int col = 1;
            for(col; col <= (n/2 + 2 - row); col++){
                cout<<"*\t";
            }
            for(int count = 1; count <= (row * 2 -1); count++){
                cout<<" \t";
            }
            col--;
            for(col; col > 0; col--){
                cout<<"*\t";
            }
        }
        else{
            int col = 1;
            for(col; col <= (row - n/2); col++){
                cout<<"*\t";
            }
            for(int count = 1; count <= (n - row) * 2 + 1; count++){
                cout<<" \t";
            }
            col--;
            for(col; col > 0; col--){
                cout<<"*\t";
            }
        }
        cout<<endl;
    }
    return 0;
}