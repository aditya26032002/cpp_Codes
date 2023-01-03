#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> pairSum(vector<int> &arr, int s)
{
    vector<vector<int>> pair;
    for (int i = 0; i < arr.size(); i++)
    {
        for(int j = i+1; j<arr.size(); j++){
            if(arr[i] + arr[j] == s){
                vector<int> temp;
                if(arr[i] < arr[j]){
                    temp.push_back(arr[i]);
                    temp.push_back(arr[j]);
                }
                else{
                    temp.push_back(arr[j]);
                    temp.push_back(arr[i]);
                }
                pair.push_back(temp);
            }
        }
    }
    sort(pair.begin(), pair.end());
    return pair;
}

int main()
{
    vector<int> arr = {2,-3,3,3,-2};
    int s = 0;
    vector<vector<int>> pair = pairSum(arr, s);
    // cout<<pair.size();
    for(int i = 0; i<pair.size(); i++){
        for(int j:pair[i]){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}