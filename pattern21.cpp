// wrong
#include <iostream>
using namespace std;

int main(){
    int n = 7;
    // cin >> n;

    for(int row = 1; row <= n; row++){
        if(row <= (n/2 + 1)){
            int col = 1;
            for(col; col <= (n - 1) - row; col++){
                cout<<"*\t";
            }
            for(int n = 1; n <= (row * 2); n++){
                cout<<"\t";
            }
            col--;
            for(col; col >= 1; col--){
                cout<<"*\t";
            }
        }
        else{
            int col = 1;
            for(col; col <= (row - 2); col++){
                cout<<"*\t";
            }
            for(int t = 1; t <= (n - row + 1) * 2; t++){
                cout<<"\t";
            }
            col--;
            for(col; col >= 1; col--){
                cout<<"*\t";
            }
        }
        cout<<endl;
    }
    
}