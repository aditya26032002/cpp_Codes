#include<bits/stdc++.h>
using namespace std;

int binaryToDecimal(string b){
    int size = sizeof(b);
    cout<<size;
    int ans = 0;
    for(int i = size-1; i>=0; i--){
        int bit = (int)b[i];
        cout<<bit<<endl;
        if(bit)
        ans += (bit << (size-1 - i));
    }
    return ans;
}

int main(){
    cout<<(pow(9, 0.5));
    // string b;
    // cout<<"Size : "<<sizeof(b)<<endl;
    // cout<<"Input string : ";
    // cin>>b;
    // cout<<binaryToDecimal(b);
    return 0;
}