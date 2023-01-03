#include<bits/stdc++.h>
using namespace std;

int findUnique(int *arr, int size){
    int xOR = 0;
    for(int i = 0; i < size; i++){
        xOR = xOR ^ (*arr);
        *arr++;
    }
    return xOR;
}

int main(){
    int arr[7] = {1,2,3,2,3,4,1};
    cout<<findUnique(arr,7);
    return 0;
}