#include <bits/stdc++.h>
using namespace std;

// O(nLogn)
// bool searchMatrix(vector<vector<int>> &matrix, int target)
// {
//     int rows = matrix.size();
//     int cols = matrix[0].size();
//     int r = 0;
//     while (r < rows)
//     {
//         int s = 0, e = cols - 1;
//         if (target >= matrix[r][s] && target <= matrix[r][e])
//         {
//             while (s <= e)
//             {
//                 int mid = s + (e - s) / 2;
//                 if (matrix[r][mid] == target)
//                     return 1;
//                 else if (matrix[r][mid] > target)
//                     e = mid - 1;
//                 else
//                     s = mid + 1;
//             }
//         }
//         r++;
//     }
//     return 0;
// }

// O(n)
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int rows = matrix.size();
    int cols = matrix[0].size();
    int r = 0, c = cols - 1;
    while (r < rows && c >= 0)
    {
        int element = matrix[r][c];
        if (element == target)
            return 1;
        else if (element < target)
            r++;
        else
            c--;
    }
    return 0;
}

int main()
{
    // vector<vector<int>> matrix = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};
    vector<vector<int>> matrix = {{5}, {6}};
    int target = 6;
    cout << searchMatrix(matrix, target);
    return 0;
}