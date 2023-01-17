#include<bits/stdc++.h>
using namespace std;

// Need some changes then will work
/*
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    int n = 0, m = 0;
    int r = 0, c = 0;
    vector<int> ans;
    while(n < (rows+1)/2 && m < (cols+1)/2){
        while(c <= (cols-1-m)){
            ans.push_back(matrix[r][c]);
            c++;
        }
        c--;r++;
        while(r <= (rows-1-n)){
            ans.push_back(matrix[r][c]);
            r++;
        }
        r--;c--;
        while(c >= m){
            ans.push_back(matrix[r][c]);
            c--;
        }
        c++;r--;n++;
        while(r >= n){
            ans.push_back(matrix[r][c]);
            r--;
        }
        r++;c++;m++;
    }
    return ans;
}
*/

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    int stRow = 0, endRow = rows-1;
    int stCol = 0, endCol = cols-1;
    int totElem = rows*cols;
    vector<int> ans;
    while(totElem > 0){
        for(int c = stCol; c<=endCol && totElem > 0; c++){
            ans.push_back(matrix[stRow][c]);
            totElem--;
        }
        stRow++;
        for(int r = stRow; r<=endRow && totElem > 0; r++){
            ans.push_back(matrix[r][endCol]);
            totElem--;
        }
        endCol--;
        for(int c = endCol; c>=stCol && totElem > 0; c--){
            ans.push_back(matrix[endRow][c]);
            totElem--;
        }
        endRow--;
        for(int r = endRow; r>=stRow && totElem > 0; r--){
            ans.push_back(matrix[r][stCol]);
            totElem--;
        }
        stCol++;
    }
    
    return ans;
}

int main(){
    vector<vector<int>> matrix = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}};
    // vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9},{10,11,12}};
    // vector<vector<int>> matrix = {{1}};
    vector<int> ans = spiralOrder(matrix);

    for(int i:ans){
        cout<<i<<" ";
    }
    return 0;
}