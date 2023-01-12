#include<bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[], int n){
    int x = 0;
    while(n-x){
        bool noSwapped = true;
        for(int i = 0, j = i+1; j<n-x; i++,j++){
            if(arr[i]>arr[j]){
                swap(arr[i], arr[j]);
                noSwapped = false;
            }
        }
        if(noSwapped)
            break;
        x++;
    }
}

void printArr(int arr[], int n){
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int arr[6] = {10,1,7,6,14,9};
    bubbleSort(arr,6);
    printArr(arr,6);
    return 0;
}