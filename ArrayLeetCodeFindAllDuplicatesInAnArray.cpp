#include<iostream>
using namespace std;

void FindDuplicates(int arr[], int len, int ans[]){
    int x = 0;
    if(len % 2 == 0)
        int len2 = len/2;
    else
        int len2 = len / 2 + 1;
    for(int i = 0; i < len - 1; i++){
        for (int j = i+1; j < len; j++)
        {
            if(arr[i] == arr[j]){
                ans[x] = arr[i];
                x++;
            }
        }
    }
    cout<<"Ans = { ";
    for (int i = 0; i < len/2; i++)
    {
        if(ans[i] == 0)
            break;
        cout<<ans[i]<<" ";
    }
    cout<<"}";
}

int main(){
    int arr[] = {4,3,2,7,8,2,3,1};
    int ans[sizeof(arr)/sizeof(arr[0])] = {0};
    FindDuplicates(arr, sizeof(arr)/sizeof(arr[0]), ans);
    return 0;
}