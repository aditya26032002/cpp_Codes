#include<bits/stdc++.h>
using namespace std;

void printArray(int arr[], int size){
    for(int i = 0; i< size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void findUniqueElements(int arr[], int size){
    int unique[size];
    int uniqueArrayIndex = 0;
    for(int i = 0; i < size; i++){
        int key = arr[i];
        for(int j = 0; j < size; j++){
            if(i == j)
            continue;
            if(key == arr[j])
            break;
            else if(j == (size - 1) && arr[j] != key){
                unique[uniqueArrayIndex] = key;
                uniqueArrayIndex++;
            }
        }
    }
    printArray(unique, uniqueArrayIndex);
}

int main(){
    int arr[6] = {1,2,3,1,2,2};
    findUniqueElements(arr,6);
    return 0;
}