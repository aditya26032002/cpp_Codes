#include<bits/stdc++.h>
using namespace std;

void moveZeroes(vector<int>& nums) {
    vector<int> notZeroes;
    int countZeroes = 0;
    int i = 0;
    while(i<nums.size()){
        if(nums[i] != 0){
            notZeroes.push_back(nums[i]);
        }
        else
            countZeroes++;
        i++;
    }
    while(countZeroes){
        notZeroes.push_back(0);
        countZeroes--;
    }
    nums = notZeroes;
}

// void moveZeroes(vector<int>& nums) {
//     int i = 0, j = i+1;
//     while(j)
// }

int main(){
    vector<int> nums = {0,1,0,3,12};
    moveZeroes(nums);
    for(int i:nums){
        cout<<i<<" ";
    }
    return 0;
}