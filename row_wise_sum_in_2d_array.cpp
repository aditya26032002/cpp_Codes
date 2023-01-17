#include<bits/stdc++.h>
using namespace std;

void rowWiseSum(int arr[][3], int rowsum[], int rows){
    for(int row = 0; row<rows; row++){
        int sum = 0;
        for(int col = 0; col<3; col++){
            sum += arr[row][col];
        }
        rowsum[row] = sum;
    }
}

void colWiseSum(int arr[][3], int colsum[], int size){
    int row;
    for(int col = 0; col<size; col++){
        int sum = 0;
        for(row = 0; row<3; row++){
            sum += arr[row][col];
        }
        colsum[col] = sum;
    }
}

int main(){
    int arr[3][3] = {{3,4,11}, {2,12,1}, {7,8,7}};
    int rowSum[3] = {0};
    int colSum[3] = {0};

    rowWiseSum(arr, rowSum, 3);
    colWiseSum(arr, colSum, 3);

    for(int i = 0; i<3; i++){
        cout<<"Sum of row "<<i+1<<" = "<<rowSum[i]<<endl;
    }
    cout<<endl;

    for(int i = 0; i<3; i++){
        cout<<"Sum of col "<<i+1<<" = "<<colSum[i]<<endl;
    }
    cout<<endl;
    return 0;
}