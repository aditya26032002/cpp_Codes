#include<bits/stdc++.h>
using namespace std;

int findPosition(vector<int>& arr, int n, int k)
{
    int ans = -1;
    int s = 0, e = n-1;
    int m = s + (e-s)/2;
    if(n == 1){
        if(arr[0] == k)
            return 0;
        return -1;
    }
    while(s < e){
        if(arr[m] < arr[0])
            e = m;
        else
            s = m+1;
        m = s + (e-s)/2;
    }
    int pivot = s;
    if(k>=arr[0]){
        s = 0;
        e = pivot-1;
    }
    else{
        s = pivot;
        e = n-1;
    }
    m = s+(e-s)/2;
    while(s<=e){
        if(arr[m] == k)
            return m;
        else if(arr[m] > k)
            e = m-1;
        else
            s = m+1;
        m = s+(e-s)/2;
    }
    return ans;
}

int main(){
    vector<int> arr = {2,4,5,6,8,9,1};
    int k = 2;
    cout<<findPosition(arr,arr.size(),k);
    return 0;
}