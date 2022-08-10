#include<iostream>
using namespace std;

int main(){
    int n = 123;
    int ans = 0;
    while(n){
        int digit = n%10;
        ans = ans * 10 + digit;
        n = n/10;
    }
    cout<<ans;
    return 0;
}