#include<bits/stdc++.h>
using namespace std;

// Recursive way
int binarySearch(int arr[], int key, int start, int end){  //For increasing order array only
    // int mid = (start + end)/2; // Will exceed int_max if start and end both int_max
    int mid = start + (end - start)/2;  //Won't exceed int_max in any case
    if(arr[mid] == key){
        return mid;
    }
    else if(start == end){
        return -1;             // Terminating condition
    }
    else if(arr[mid] < key){
        start = mid + 1;
        return binarySearch(arr, key, start, end);
    }
    else if(arr[mid] > key){
        end = mid;
        return binarySearch(arr, key, start, end);
    }
}

// Without recursion
int binarySearch(int arr[], int size, int key){  //For increasing order array only
    int start = 0, end = size-1;
    while(1){
        // int mid = (start + end)/2; // Will exceed int_max if start and end both int_max
        int mid = start + (end - start)/2; //Won't exceed int_max in any case
        if(arr[mid] == key)
            return mid;
        else if(start == end)
            return -1;
        else if(arr[mid] < key)
            start = mid + 1;
        else if(arr[mid] > key)
            end = mid;
    }
}

int main(){
    int arr[11] = {1,2,3,4,5,6,8,9,10,12,14};
    int key = 10, start = 0, end = 10-1;
    cout<<"Key is at index : "<<binarySearch(arr,key,start,end)<<endl;
    cout<<"Key is at index : "<<binarySearch(arr,11,key)<<endl;
    return 0;
}