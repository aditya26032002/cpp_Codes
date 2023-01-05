#include<bits/stdc++.h>
using namespace std;

bool isPossibleSoln(vector<int> &boards, int k, int mid){
    int painterNo = 1;
    int boardSum = 0;
    for(int i = 0; i<boards.size(); i++){
        if(boardSum + boards[i] <= mid){
            boardSum+=boards[i];
        }
        else{
            painterNo++;
            if(painterNo > k || boards[i] > mid){
                return false;
            }
            boardSum = 0;
            boardSum = boards[i];
        }
    }
    return true;
}

int findLargestMinDistance(vector<int> &boards, int k)
{
    int s = 0;
    int totBoards = 0;
    for(int i:boards){
        totBoards+=i;
    }
    int ans = -1;
    int e = totBoards;
    int mid = s + (e-s)/2;
    while(s<=e){
        if(isPossibleSoln(boards,k,mid)){
            ans = mid;
            e = mid-1;
        }
        else{
            s = mid+1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}

int main(){
    vector<int> boards = {5, 10, 1, 3, 2, 4, 2, 9, 2, 8};
    cout<<findLargestMinDistance(boards, 3);
    return 0;
}