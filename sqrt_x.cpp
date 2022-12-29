#include<bits/stdc++.h>
using namespace std;

int sqrt(int x){
    if(x == 1){
        return 1;
    }
    else if(x==0){
        return 0;
    }
    int i,j;
    for(i = 2, j = x/2; i <= j; i++){
        if(x % i == 0){
            j = x/i;
            // cout<<"i:"<<i<<" j:"<<j<<endl;
        }
        if(i == j)
        break;
    }
    // cout<<"Final i,j:"<<i<<" "<<j<<endl;
    if(i == j){
        return i;
    }
    else{
        return -1;
    }
}

int main(){
    int n = 81;
    int root = sqrt(n);
    // cout<<root;
    if(root == -1){
        cout<<"No perfect square";
    }
    else
    cout<<"Square root is : "<<root;
    return 0;
}