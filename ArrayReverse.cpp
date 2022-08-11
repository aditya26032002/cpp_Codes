#include<iostream>
using namespace std;

void reverseArray(int arr[], int len){
    int temp;
    for(int i = 0; i < len/2; i++){
        temp = arr[i];
        arr[i] = arr[len - 1 - i];
        arr[len - 1 - i] = temp;
    }
}

int main(){
    int arr[] = {1,2,3,4,5};
    reverseArray(arr, 5);
    for (int i = 0; i < 5; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}