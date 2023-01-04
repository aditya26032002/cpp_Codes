#include<bits/stdc++.h>
using namespace std;

int pivot(int arr[], int n){
    int s=0, e=n-1;
    int m = s + (e-s)/2;
    while(s<e){
        if(arr[m] < arr[0])
        e = m;
        else
        s = m+1;
        m = s + (e-s)/2;
    }
    return s;
}

int main(){
    int arr[5] = {7,9,1,2,3};
    cout<<arr[pivot(arr,5)];
    return 0;
}