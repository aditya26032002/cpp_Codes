#include<bits/stdc++.h>
using namespace std;

int duplicate(vector<int> &arr){
    int size = arr.size();
    long int maxSum = (size*(size+1))/2;
    long int sum = 0;
    for(int i:arr){
        sum += i;
    }
    return size-(maxSum - sum);
}

// Second approach:
// XOR with values 1 to n-1, will cancel 1 to n-1 in arr
// and remain with 1 last value that is twice
int duplicate2(vector<int> &arr){
    int ans = 0;
    for(int i:arr){
        ans ^= i;
    }
    for(int i= 1; i < arr.size(); i++){
        ans ^= i;
    }
    return ans;
}

int main(){
    vector<int> arr = {1,2,4,2,3};
    cout<<duplicate(arr)<<endl;
    cout<<duplicate2(arr)<<endl;
    //checking if value overflow int
    // long int x = (100000*(100001))/2;
    // cout<<x;
    return 0;
}