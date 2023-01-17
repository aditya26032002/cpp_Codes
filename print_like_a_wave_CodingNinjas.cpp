#include<bits/stdc++.h>
using namespace std;

vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols)
{
    vector<int> ans;
    for(int col =0; col<mCols; col++){
        if(col%2 == 0){
            int row = 0;
            while(row<nRows){
                ans.push_back(arr[row++][col]);
            }
        }
        else{
            int row = nRows-1;
            while(row>=0){
                ans.push_back(arr[row--][col]);
            }
        }
    }
    return ans;
}

int main(){
    vector<vector<int>> arr = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}};
    vector<int> ans = wavePrint(arr, 3, 4);
    
    for(int i:ans){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}