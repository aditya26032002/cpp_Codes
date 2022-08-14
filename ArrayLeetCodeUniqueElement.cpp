#include<iostream>
using namespace std;

/* 1st Approach */
// int linearSearch(int arr[], int len, int key, int index){
//     while (index < len)
//     {
//         if(arr[index] == key){
//             return 1;
//         }
//         index++;
//     }
//     return 0;
// }

// void FindUnique(int arr[], int len){
//     for (int i = 0; i < len; i++)
//     {
//         if((linearSearch(arr, i, arr[i], 0) == 0)
//             & (linearSearch(arr, len, arr[i], i + 1) == 0)){
//             cout<<"Found Unique : "<<arr[i];
//             return;
//         }
//     }
// }

int FindUnique(int arr[], int len){
    int ans = 0;
    for (int i = 0; i < len; i++)
    {
        ans = ans ^ arr[i];
    }
    return ans;
}

int main(){
    int arr[] = {2, 3, 1, 6, 3, 6, 2};
    // FindUnique(arr, sizeof(arr)/sizeof(arr[0]));
    cout<< FindUnique(arr, sizeof(arr)/sizeof(arr[0]));

    // int a = 3;
    // int b = 3;
    // cout<< (a ^ b);
    return 0;
}