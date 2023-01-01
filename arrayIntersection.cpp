#include<bits/stdc++.h>
using namespace std;

void printArray(int arr[], int size){
    for(int i = 0; i< size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void intersection(int arr1[], int size1, int arr2[], int size2){
    int intersecting[min(size1,size2)];
    int index = 0;
    for(int i = 0; i < size1; i++){
        int key = arr1[i];
        for(int j = 0; j < size2; j++){
            if(key == arr2[j]){
                arr2[j] = INT_MIN;
                intersecting[index] = key;
                index ++;
                break;
            }
        }
    }
    printArray(intersecting, index);
}

int main(){
    int arr1[6] = {1,2,3,1,7,2};
    int arr2[5] = {5,6,7,3,9};
    intersection(arr1, 6, arr2, 5);
    return 0;
}