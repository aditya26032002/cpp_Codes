#include<bits/stdc++.h>
using namespace std;

int main(){
    // int last_term = 16;  // 1st approach
    // int a = 0, b = 1;
    // cout<<a<<" ";
    // int sum = a + b;

    // for(sum; sum <= last_term; sum = a + b){
    //     cout<<sum<<" ";
    //     a = b;
    //     b = sum;
    // }

    int a = 0, b = 1;  // 2nd approach
    int sum = 0;

    cout<<a<<" "<<b<<" ";

    for(int i = 1; i <= 10; i++){
        sum = a + b;
        cout<<sum<<" ";
        a = b;
        b = sum;
    }

    // int n = 8;  // 3rd approach
    // int a = 0, b = 1;
    // cout<<a<<" ";

    // for(int i = 0; i <= (n-2); i++){
    //     int nextFib = a + b;
    //     cout<<nextFib<<" ";
    //     b = a;
    //     a = nextFib;
    // }
    
    return 0;
}