#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
	vector<vector<int>> triplet;
    sort(arr.begin(), arr.end());
    for(int i = 0; i<arr.size(); i++){
        if(arr[i] < K)
        for(int j = i+1; j<arr.size(); j++){
            if(arr[i] + arr[j] <= K)
            for(int k = j+1; k<arr.size(); k++){
                if(arr[i] + arr[j] + arr[k] == K){
                    vector<int> temp;
                    temp.push_back(arr[i]);
                    temp.push_back(arr[j]);
                    temp.push_back(arr[k]);
                    triplet.push_back(temp);
                }
                else if(arr[i] + arr[j] + arr[k] > K){
                    break;
                }
            }
        }
    }
    return triplet;
}

int main(){
    vector<int> arr = {10,5,5,5,2};
    int n = 5, sum = 12;
    vector<vector<int>> triplet = findTriplets(arr,n,sum);
    for(int i = 0; i<triplet.size(); i++){
        for(int j:triplet[i]){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}