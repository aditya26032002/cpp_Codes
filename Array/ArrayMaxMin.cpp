#include<iostream>
using namespace std;

void maxMin(int arr[], int len){
    int indexMax = 0, valueMax = arr[0];
    int indexMin = 0, valueMin = arr[0];
    for(int i = 1; i< len; i++){
        if(arr[i] > valueMax){
            valueMax = arr[i];
            indexMax = i;
        }
        if (arr[i] < valueMin)
        {
            indexMin = i;
            valueMin = arr[i];
        }
        
    }
    cout<<"Max value = "<<valueMax<<"\nIndex = "<<indexMax<<endl<<endl;
    cout<<"Min value = "<<valueMin<<"\nIndex = "<<indexMin<<endl;
}

int main(){
    int arr[6] = {12,10,14,11,10,2};
    maxMin(arr, 6);
    return 0;
}