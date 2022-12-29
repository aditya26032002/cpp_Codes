#include<bits/stdc++.h>
using namespace std;

int reverse(int x){
    int reversed = 0;
    int n = x;
    while(n){
        reversed = (reversed*10 + n%10);
        n/=10;
        if(reversed >= INT_MAX)
        return 0;
    }
    return reversed;
}

int main(){
    int n = -123;
    cout<<reverse(n);
    return 0;
}