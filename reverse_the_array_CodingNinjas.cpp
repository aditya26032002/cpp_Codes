#include<bits/stdc++.h>
using namespace std;

void reverseAfterGivenIndex(vector<int> &arr, int m){
    int i = m+1, j = arr.size()-1;
    while(i<j){
        swap(arr[i],arr[j]);
        i++;
        j--;
    }
}

int main(){
    vector<int> arr = {10,4,5,2,3,6,1,3,6};
    reverseAfterGivenIndex(arr, 3);
    
    for(auto i:arr){
        cout<<i<<" ";
    }
    return 0;
}