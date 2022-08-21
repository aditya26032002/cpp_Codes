#include <iostream>
using namespace std;

int main(int argc, char **argv){
    int n = 5;
    // cin >> n;
    
    for(int row = 1; row <= n; row++){
        for(int col = 1; col <= row; col++){
            if(col < row)
                cout<<"\t";
            else
                cout<<"*\t";
        }
        cout<<endl;
    }
}