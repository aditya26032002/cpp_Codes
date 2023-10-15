#include<iostream>
using namespace std;

int main(){
    int n = 7;
    int sum = 1;
    int prev = 0;
    int current = 1;
    for(int row = 1; row <= n; row++){
        for(int col = 1; col <= row; col++){
            if(row == 1){
                cout<<"0\t";
            }
            else{
                cout<<sum<<"\t";
                sum = prev + current;
                prev = current;
                current = sum;
            }
        }
        cout<<endl;
    }
    return 0;
}