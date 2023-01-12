#include<bits/stdc++.h>
using namespace std;

bool check(vector<int>& nums) {
    int size = nums.size();
    // int ans = true;
    if(nums.front()<nums.back()){
        // no pivot
        for(int i = 0; i < size-1; i++){
            if(nums[i+1] < nums[i])
                return false;
        }
    }
    else{
        int pivot = 0;
        for(int i = 0; i<size-1; i++){
            if(nums[i+1]<nums[i])
                pivot++;
            if(pivot > 1)
                return false;
        }
    }
    return true;
}

// bool check(vector<int>& nums){
//     int count = 0;
//     int n = nums.size();
//     for(int i = 1; i<n; i++){
//         if(nums[i-1]>nums[i])
//             count++;
//     }
//     if(nums[n-1] > nums[0])
//         count++;
    
//     return (count<=1);
// }

int main(){
    vector<int> arr = {6,10,6};
    cout<<check(arr);
    return 0;
}