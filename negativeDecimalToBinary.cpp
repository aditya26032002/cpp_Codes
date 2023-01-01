#include<bits/stdc++.h>
using namespace std;

// Not working perfectly


int negativeDecToBinary(int n){
    int arr[32];
    int flag = 1;
    for(int i = 31; i>=0; i--){
        int bit = n & 1;
        // cout<<bit;
        if(bit && flag){
            cout<<"Worked once"<<endl;
            arr[i] = bit;
            flag = 0;
            continue;
        }
        if(bit == 1){
            arr[i] = 0;
        }
        else if(bit == 0){
            arr[i] = 1;
        }
        n = n >> 1;
    }
    for(int i = 0; i < 32; i++){
        cout<<arr[i];
    }
}

int main(){
    int n;
    cout<<"Input n: ";
    cin>>n;
    negativeDecToBinary(n);
    return 0;
}