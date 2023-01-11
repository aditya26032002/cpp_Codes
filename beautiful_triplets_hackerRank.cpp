#include<bits/stdc++.h>
using namespace std;

int search(int arr[], int i, int j, int searchVal){
    int s = i+1, e = j-1;
    int mid = s + (e-s)/2;
    while(s<=e){
        if(arr[mid] == searchVal)
            return 1;
        else if(arr[mid] > searchVal)
            e = mid-1;
        else
            s = mid+1;
        mid = s + (e-s)/2;
    }
    return 0;
}

int countTriplets(int arr[], int n, int d){
    int triplets = 0;
    for(int i = 0; i<n-2; i++){
        for(int j = n-1; j>i+1; j--){
            if(arr[j] == arr[i] + 2*d){
                int searchVal = arr[i] + d;
                triplets+=(search(arr,i,j,searchVal));
            }
            else if(arr[j] < arr[i] + 2*d){
                break;
            }
        }
    }
    return triplets;
}

int main(){
    int arr[7] = {1,2,4,5,7,8,10};
    int d = 3;
    cout<<countTriplets(arr,7,3);
    return 0;
}