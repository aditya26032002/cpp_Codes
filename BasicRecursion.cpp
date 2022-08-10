#include<iostream>
using namespace std;

void printDecreasing(int n){
    if(n==0)
        return;
    cout<<n<<endl;
    printDecreasing(n-1);
}

void printIncreasing(int n){
    if(n==0)
        return;
    printIncreasing(n-1);
    cout<<n<<endl;
}

void printDecreaseThenIncrease(int n){
    if(n == 0)
        return;
    cout<<n<<endl;
    printDecreaseThenIncrease(n-1);
    cout<<n<<endl;
}

int factorial(int n){
    if(n >= 1)
        return n;
    else
        return n*factorial(n-1);
}

int pow(int x,int n){
    if(n == 0)
        return 1;
    else
        return x*pow(x,n-1);
}

int pow_lowComplex(int x, int n){
    if(n == 0)
        return 1;
    int z = pow_lowComplex(x, n/2);
    if(n%2 != 0)
        return x*z*z;
    return z*z;
}

void TOH(int n, char A, char B, char C){
    if(n == 0)
        return;
    TOH(n-1, A, C, B);
    cout<<"Moved disc "<<n<<" from "<<A<<" to "<<B<<endl;
    TOH(n-1,C,B,A);
}

int main(){
    printDecreasing(5);
    printIncreasing(5);
    printDecreaseThenIncrease(5);
    cout<<factorial(5)<<endl;
    cout<<pow(5,3)<<endl;
    cout<<pow_lowComplex(5,3)<<endl;
    TOH(3,'A','B','C');
    return 0;
}