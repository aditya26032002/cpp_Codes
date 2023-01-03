#include<bits/stdc++.h>
using namespace std;

void sort01(int arr[], int n){
    int i = 0, j = n-1;
    while(i<j){
        if(arr[i] > arr[j]){
            swap(arr[i],arr[j]);
        }
        else if(arr[i] == 0){
            i++;
        }
        else if(arr[j] == 1){
            j--;
        }
        else{
            i++;
            j--;
        }
    }
}

int main(){
    int arr[6] = {0,1,0,1,0,0};
    sort01(arr, 6);
    for(int i = 0; i<6; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}