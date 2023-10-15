// wrong
#include<iostream>
using namespace std;

bool uniqueOrNot(int arr[], int len){
    int ans = 0;
    for (int i = 0; i < len; i++)
    {
        ans = ans ^ arr[i];
        if (ans != 0)
        {
            cout<<"All unique"<<endl;
            return true;
        }
    }
    cout<<"No unique"<<endl;
    return false;
    // if (ans == 0)
    // {
    //     cout<<"Not any element is unique"<<endl;
    //     return false;
    // }
    // else{
    //     cout<<"At least one is unique"<<endl;
    //     return true;
    // }
}

int main(){
    // int arr[] = {2, 3, 1, 6, 3, 6, 2};
    // int arr[] = {1, 2, 2, 1, 1, 3};
    int arr[] = {1, 2};
    // int arr[] = {-3, 0, 1, -3, 1, 1, 1, -3, 10, 0};
    cout<<uniqueOrNot(arr, sizeof(arr)/sizeof(arr[0]));
    return 0;
}