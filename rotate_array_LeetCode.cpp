#include<bits/stdc++.h>
using namespace std;

void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> temp(n);
    for(int i = 0; i<n; i++){
        temp[(i+k)%n] = nums[i];
    }
    nums = temp;
}

int main(){
    vector<int> nums = {1,2,3,4,5,6,7};
    int k = 3;
    rotate(nums,k);
    for(int i:nums){
        cout<<i<<" ";
    }
    return 0;
}

// void rotate(vector<int>& nums, int k) {
//     vector<int> elements;
//     int j = 0, i = nums.size()-1;
//     while(j<k){
//         elements.push_back(nums[i-j]);
//         j++;
//     }
//     i = k;
//     while(i<nums.size()){
//         nums[i] = nums[i-k];
//         i++;
//     }
//     i = 0;
//     j = 0;
//     while(i<k){
//         nums[i] = elements[j];
//         i++; j++;
//     }
// }

// TLE
// void rotate(vector<int>& nums, int k) {
//     int size = nums.size();
//     while(k){
//         int i = size-1;
//         int temp = nums[i];
//         for(; i>0; i--){
//             nums[i] = nums[i-1];
//         }
//         nums[i] = temp;
//         k--;
//     }
// }
