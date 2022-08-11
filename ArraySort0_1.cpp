#include<iostream>
using namespace std;

void sort(int arr[], int len){
    int zeros = 0;
    int i = 0;
    while(i < len){
        if (arr[i]==0)
        {
            zeros++;
        }
        i++;
    }
    i = 0;
    while (i < zeros)
    {
        arr[i] = 0;
        i++;
    }
    while (i < len)
    {
        arr[i] = 1;
        i++;
    }
}

int main(){
    int arr[]= {0,1,0,1,1,1,0,0,0,1,0,1};
    int len = sizeof(arr)/sizeof(arr[0]);
    sort(arr, len);

    for (int i = 0; i < len; i++)
    {
        cout<<arr[i]<<", ";
    }
    
    return 0;
}