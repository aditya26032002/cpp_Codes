#include<bits/stdc++.h>
using namespace std;

int main(){
    int n = 264;
    int product = 1, sum = 0;
    while(n){
        product*=n%10;
        sum+=n%10;
        n/=10;
    }
    cout<<"Product : "<<product<<endl;
    cout<<"Sum : "<<sum<<endl;
    cout<<"Difference : "<<product-sum<<endl;
    return 0;
}