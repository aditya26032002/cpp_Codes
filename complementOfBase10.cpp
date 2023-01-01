#include<bits/stdc++.h>
using namespace std;

int compliment(int n){
    int x = ~n, mask = 0, result;
    while(n){
        n = n>>1;
        mask = (mask << 1) | 1;
    }
    result = x & mask;
    return result;
}

// int compliment(int n){
//     int index = 0;
//     int reversed = 0;
//     while(n){
//         if(n%2 == 0)
//         reversed += (1 << index);
//         n/=2;
//         index++;
//     }
//     return reversed;
// }

int main(){
    int n = 5;
    cout<<compliment(n);
    return 0;
}