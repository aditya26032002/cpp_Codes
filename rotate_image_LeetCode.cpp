#include<bits/stdc++.h>
using namespace std;

// Space : O(numOfElements)
// void rotate(vector<vector<int>>& matrix) {
//     int size = matrix.size();
//     int ans[size][size];
//     // vector<vector<int>> ans2(size);
//     for(int i = 0, j = size-1-i; i<size && j>=0; i++, j--){
//         for(int k = 0; k<size; k++){
//             ans[k][j] = matrix[i][k];
//         }
//     }
//     for(int i = 0; i<size; i++){
//         for(int j = 0; j<size; j++){
//             matrix[i][j] = ans[i][j];
//         }
//     }
// }

void rotate(vector<vector<int>>& matrix) {
    int size = matrix.size();
    int stCol = 0, enCol = size-1;
    int stRow = 0, enRow = size-1;
    while(stCol < enCol){
        int temp[size];
        int index = 0;
        // enRow copied to stCol
        for(int rstCol = stRow, cenRow = stCol; rstCol<=enRow; rstCol++, cenRow++, index++){
            temp[index] = matrix[rstCol][stCol];
            matrix[rstCol][stCol] = matrix[enRow][cenRow];
        }
        // enCol copied to enRow
        for(int cenRow = stCol, renCol = enRow; cenRow<=enCol; cenRow++, renCol--){
            matrix[enRow][cenRow] = matrix[renCol][enCol];
        }
        // stRow copied to enCol
        for(int renCol = enRow, cstRow = enCol; renCol>=stRow; renCol--, cstRow--){
            matrix[renCol][enCol] = matrix[stRow][cstRow];
        }
        // temp copied to stRow
        for(int cstRow = enCol, i = 0; cstRow>=stCol; cstRow--, i++){
            matrix[stRow][cstRow] = temp[i];
        }
        stCol++;
        enCol--;
        stRow++;
        enRow--;
    }
}

int main(){
    // vector<vector<int>> matrix = {{1,2,3}, {4,5,6}, {7,8,9}};
    vector<vector<int>> matrix = {{5,1,9,11}, {2,4,8,10}, {13,3,6,7}, {15,14,12,16}};
    rotate(matrix);

    for(vector<int> i:matrix){
        for(int j:i){
            cout<<j<<"\t";
        }
        cout<<endl;
    }
    return 0;
}