#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[11] = {1,2,3,4,5,6,7,8,9,10,11};
    int size = sizeof(arr)/sizeof(arr[0]);
    int upTillIndex = size/2 - 1;

    for(int i = 0; i <= upTillIndex; i++){
        int temp = arr[i];
        arr[i] = arr[(size-1)-i];
        arr[(size-1)-i] = temp;
    }

    for(int i=0; i < size; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}