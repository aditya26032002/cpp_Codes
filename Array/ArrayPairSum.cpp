#include<iostream>
using namespace std;

void pairSum(int arr[], int len, int sum){
    for (int i = 0; i < len; i++)
    {
        for (int j = i+1; j < len; j++)
        {
            if(arr[i] + arr[j] == sum){
                cout<<"Found a pair : "<<arr[i]<<", "<<arr[j]<<endl;
            }
        }
    }
    
}

int main(){
    int arr[] = {0, -1, 2, -3, 1, -2};
    int sum = -2;
    pairSum(arr, 6, -2);
    return 0;
}