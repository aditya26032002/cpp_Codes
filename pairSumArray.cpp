#include<bits/stdc++.h>
using namespace std;

void pairSum(int arr[], int size, int sum){
    for(int i = 0; i < size; i++){
        for(int j = i+1; j < size; j++){
            if((arr[i] + arr[j]) == sum){
                cout<<"Found a pair : "<<arr[i]<<", "<<arr[j]<<endl;
            }
        }
    }
}

int main(){
    int arr[10] = {1,2,3,4,5,6,7,8,9,0};
    int sum = 12;
    pairSum(arr, 10, sum);
    return 0;
}