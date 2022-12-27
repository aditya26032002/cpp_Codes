#include<bits/stdc++.h>
using namespace std;

int hemmingWeight(uint32_t n){
    int count = 0;
    while(n!=0){
        if(n & 1){
            count++;
        }
        n = n>>1;
    }
    return count;
}

int main(){
    uint32_t n = 15;
    cout<<hemmingWeight(n);
    return 0;
}