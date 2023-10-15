#include<iostream>
using namespace std;

int linearSearch(int arr[], int len, int key, int index){
    while (index < len)
    {
        if(arr[index] == key){
            return 1;
        }
        index++;
    }
    return 0;
}

void findDuplicateElements(int arr[], int duplicateElements[], int len){
    int i = 0, j = 0;
    while (i < len)
    {
        if(linearSearch(arr,len,arr[i], i+1)){
            if (linearSearch(duplicateElements,j,arr[i],0) == 0)
            {
                duplicateElements[j] = arr[i];
                j++;
            } 
        }
        i++;
    }
    
}

int main(){
    int arr[7] = {1,2,3,4,5,2,4};
    int duplicateElements[7] = {0};
    findDuplicateElements(arr, duplicateElements, 7);
    int i = 0;
    while (i < 7)
    {
        if(duplicateElements[i] == 0){
            break;
        }
        cout<<duplicateElements[i]<<" ";
        i++;
    }
    
    return 0;
    return 0;
}