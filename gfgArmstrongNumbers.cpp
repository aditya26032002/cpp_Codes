#include<bits/stdc++.h>
using namespace std;

string ArmstrongOrNot(int num){
    int temp = num;
    int sum = 0, digit;
    while(temp){
        digit = temp%10;
        sum += pow(digit,3);
        temp /= 10;
    }
    if(sum == num){
        return "Yes";
    }
    else{
        return "No";
    }
}

int main(){
    int num = 153;
    cout<<ArmstrongOrNot(num);
    return 0;
}
