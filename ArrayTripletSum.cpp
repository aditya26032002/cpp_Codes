#include<iostream>
using namespace std;

void tripletSum(int arr[], int len, int sum){
    for (int i = 0; i < len; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            for (int k = j + 1; k < len; k++)
            {
                if(arr[i] + arr[j] + arr[k] == sum){
                    cout<<"Found a triplet : "<<arr[i]<<", "<<arr[j]<<", "<<arr[k]<<endl;
                }
            }   
        }   
    }
}

int main(){
    int arr[] = {12, 3, 4, 1, 6, 9, 7, 13}, sum = 24;
    tripletSum(arr, 8, sum);
    return 0;
}