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

void findUniqueElements(int arr[], int uniqueElements[], int len){
    int i = 0, j = 0;
    while (i < len)
    {
        if(linearSearch(arr,len,arr[i], i+1) || linearSearch(arr,i,arr[i],0)){}
        else{
            uniqueElements[j] = arr[i];
            j++;
        }
        i++;
    }
    
}

int main(){
    int arr[7] = {1,2,3,4,5,2,4};
    int uniqueElements[7] = {0};
    findUniqueElements(arr, uniqueElements, 7);
    int i = 0;
    while (i < 7)
    {
        if(uniqueElements[i] == 0){
            break;
        }
        cout<<uniqueElements[i]<<" ";
        i++;
    }
    
    return 0;
}