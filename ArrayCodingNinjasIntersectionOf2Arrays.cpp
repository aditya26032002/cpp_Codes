#include<iostream>
// #include <bits/stdc++.h> //error
using namespace std;

#define INT_MIN (-2147483647 - 1)

int main(){
    int arr1[] = {1,2,3};
    int len1 = sizeof(arr1)/sizeof(arr1[0]);
    int arr2[] = {3,4,5};
    int len2 = sizeof(arr2)/sizeof(arr2[0]);

    // Non optimized
    // for (int i = 0; i < len1; i++)
    // {
    //     for (int j = 0; j < len2; j++)
    //     {
    //         if(arr1[i] < arr2[j]){
    //             break;
    //         }
    //         if(arr1[i] == arr2[j]){
    //             cout<<arr1[i]<<" ";
    //             arr2[j] = INT_MIN;
    //             break;
    //         }
            
    //     }
    // }

    // Optimized
    int i =0, j = 0;
    while((i < len1) & (j < len2)){
        if(arr1[i] < arr2[j]){
            i++;
        }
        else if(arr1[i] == arr2[j]){
            cout<<arr1[i]<<" ";
            i++;
            j++;
        }
        else{
            j++;
        }
    }
    
    return 0;
}