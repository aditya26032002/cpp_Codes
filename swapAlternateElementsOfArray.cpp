#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[7] = {1,2,3,4,5,6,7};
    int size = 7;
    int start = 0;

    while((start+1) < size){
        swap(arr[start],arr[start+1]);
        start+=2;
    }

    for(int i=0; i < size; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}