#include<bits/stdc++.h>
using namespace std;

bool isPossibleSol(vector<int> &stalls, int k, int mid){
    int size = stalls.size();
    int position = stalls[0];
    int cowCount = 1;
    for(int i = 1; i<size; i++){
        int distance = stalls[i] - position;
        if(distance >= mid){
            cowCount++;
            if(cowCount == k)
            return true;
            position = stalls[i];
        }
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(), stalls.end());
    int s = 0;
    int e = stalls.back();
    int m = s + (e-s)/2;
    int ans = -1;
    while(s<=e){
        if(isPossibleSol(stalls, k, m)){
            ans = m;
            s = m+1;
        }
        else{
            e = m-1;
        }
        m = s+(e-s)/2;
    }
    return ans;
}

int main(){
    vector<int> stalls = {17,93,75,67,74,92,8,83,60,35};
    cout<<aggressiveCows(stalls, 4);
    return 0;
}