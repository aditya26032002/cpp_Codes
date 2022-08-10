#include<iostream>
#include <math.h>
using namespace std;

void decimal(int binary_num){
    int ans = 0, i = 0;
    while(binary_num != 0){
        int digit = binary_num % 10;
        if(digit == 1)
            ans = ans + digit * pow(2, i);
        binary_num = binary_num/10;
        i++;
    }
    cout<<ans;
}

int main(){
    int binary_num;
    cout<<"Enter binary number : ";
    cin>>binary_num;
    decimal(binary_num);
    return 0;
}