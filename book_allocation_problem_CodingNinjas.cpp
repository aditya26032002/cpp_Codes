#include<bits/stdc++.h>
using namespace std;

bool isPossibleSoln(int arr[], int n, int m, int mid){
    int studentNo = 1;
    int pageSum = 0;
    for(int i = 0; i<n; i++){
        if(pageSum + arr[i] <= mid){
            pageSum+=arr[i];
        }
        else{
            studentNo++;
            if(studentNo > m || arr[i] > mid){
                return false;
            }
            pageSum = 0;
            pageSum = arr[i];
        }
    }
    return true;
}

int ret(int arr[], int n, int m){
    int arrSum = 0;
    for(int i = 0; i<n; i++){
        arrSum += arr[i];
    }
    int start = 0, end = arrSum;
    int mid = start + (end-start)/2;

    int ans = -1;

    while(start<=end){
        if(isPossibleSoln(arr,n,m,mid)){
            ans = mid;
            end = mid-1;
        }
        else{
            start = mid+1;
        }
        mid = start + (end - start)/2;
    }
    return mid;
}

int main(){
    int pages[4] = {5,17,100,11};
    cout<<ret(pages,4,4);
    return 0;
}