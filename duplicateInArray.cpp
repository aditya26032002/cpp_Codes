#include<bits/stdc++.h>
using namespace std;

void printArray(int arr[], int size){
    for(int i = 0; i< size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void findDuplicateElements(int arr[], int size){
    int duplicates[size];
    int index = 0;
    for(int i = 0; i < size; i++){
        int key = arr[i];
        for(int j = 0; j < size; j++){
            if(i == j)
            continue;
            if(key == arr[j]){
                if(index == 0){
                    duplicates[index] = key;
                    index++;
                    break;
                }
                for(int l = 0; l < index; l++){
                    if(key == duplicates[l])
                    break;
                    else if((duplicates[l] != key) && (l == (index-1))){
                        duplicates[index] = key;
                        index++;
                    }
                }
                break;
            }
        }
    }
    printArray(duplicates, index);
}

int main(){
    int arr[6] = {1,2,3,1,2,2};
    findDuplicateElements(arr, 6);
    return 0;
}