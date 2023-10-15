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

void intersection(int arr1[], int arr2[], int len1, int len2){
    cout<<"Intersection = { ";
    for (int i = 0; i < len1; i++)
    {
        if(linearSearch(arr2,len2,arr1[i],0)){
            cout<<arr1[i]<<" ";
        }
    }
    cout<<"}";
}

int main(){
    int arr1[7] = {1,2,3,4,5,6,7};
    int arr2[7] = {5,6,8,9,10,11,4};
    intersection(arr1,arr2,7,7);
    return 0;
}