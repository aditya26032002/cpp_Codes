#include<iostream>
using namespace std;

long long power(int x, int toThe){
    long long ans = 1;
    while (toThe)
    {
        ans = ans * x;
        toThe--;
    }
    return ans;
}

void decimalToBinary(long long n, int bits[],int currPosition, int lastPosition)
{
    int quotient, remainder;
    quotient = n / 2;
    remainder = n % 2;
    bits[currPosition] = remainder;

    if ((quotient == 0) || (currPosition == lastPosition))
    {
        return;
    }
    else
    {
        currPosition++;
        decimalToBinary(quotient, bits, currPosition, lastPosition);
    }
}

long long binaryToDecimal(int bits[], int lastPosition){
    long long ans = 0;
    for (int i = 0; i <= lastPosition; i++)
    {
        if(bits[i] != 0)
            ans = ans + bits[i]*power(2,lastPosition-i);
    }
    return ans;
}

// Easiest approach----
// long long reversedBits(long long x) {
//         // code here
//  int k=31;
//  long long ans=0;
//  while(x!=0){
//      int bit=(x&1);
//      ans+=(bit*pow(2,k));
//      k--;
//      x>>=1;
//  }
//  return ans;
//  }

int main(){
    long long num = 4294967295;
    int bits[32] = {0};
    decimalToBinary(num, bits,0, 31);
    for(int i = 0; i < 32; i++){
        cout<<bits[i];
    }
    cout<<endl<<binaryToDecimal(bits, 31)<<endl;

    // reversedBits(num); //Easier approach---
    return 0;
}
