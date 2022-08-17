#include<iostream>
using namespace std;

// void searchDuplicate(int arr[], int len){
//     for(int i = 0; i < len; i++){
//         for (int j = i+1; j < len; j++)
//         {
//             if(arr[i] == arr[j]){
//                 cout<<"Duplicate : "<<arr[i];
//                 return;
//             }
//         }
        
//     }
// }

void searchDuplicate(int arr[], int len){
    int ans = 0;
    for (int i = 0; i < len; i++)
    {
        ans = ans ^ arr[i];
        ans = ans ^ i;
    }
    cout<<ans;
    
}

int main(){
    int arr[] = {5,1,2,3,4,2};
    searchDuplicate(arr, sizeof(arr)/sizeof(arr[0]));
    return 0;
}