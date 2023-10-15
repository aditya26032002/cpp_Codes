#include<iostream>
using namespace std;

int main(){
    int n = 5;
    char ch = 'A';
    for(int row = 1; row <= n; row++){
        int col = 1;
        char p = ch + n-row;
        for(col; col<= row; col++){
            cout<<p<<"\t";
            p++;
        }
        cout<<endl;
    }
    return 0;
}