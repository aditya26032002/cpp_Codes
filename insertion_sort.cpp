#include<bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int n){
    for(int i = 1; i<n; i++){
        int j = i-1, temp = arr[i];
        while(j>=0){
            if(arr[j]>temp){
                arr[j+1] = arr[j];
            }
            else
                break;
            j--;
        }
        arr[j+1] = temp;
    }
}

void printArr(int arr[], int n){
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int arr[7] = {10,1,7,4,8,2,11};
    insertionSort(arr,7);
    printArr(arr,7);
    return 0;
}