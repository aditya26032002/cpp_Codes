#include<bits/stdc++.h>
using namespace std;

bool isPossibleSol(vector<int> &rank, int m, int mid){
    int dishNo = 0;
    for(int i = 0; i<rank.size(); i++){
        int time = 0;
        int count = 1;
        while(1){
            if(time + count*rank[i] <= mid){
                time+=count*rank[i];
                count++;
                dishNo++;
                if(dishNo == m){
                    return true;
                }
            }
            else
                break;
        }
    }
    return false;
}

int minCookTime(vector<int> &rank, int m)
{
    sort(rank.begin(), rank.end());
    int ans = -1;
    int s = 0, e = (rank.back())*m*(m+1)/2;
    int mid = s + (e-s)/2;
    while(s<=e){
        if(isPossibleSol(rank,m,mid)){
            ans = mid;
            e = mid-1;
        }
        else
            s = mid+1;
        mid = s + (e-s)/2;
    }
    return ans;
}

int main(){
    vector<int> rank = {1,2,3,4};
    int dishes = 10;
    cout<<minCookTime(rank, dishes);
    return 0;
}