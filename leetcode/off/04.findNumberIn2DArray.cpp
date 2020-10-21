#include <iostream>
#include <vector>
using namespace std;

bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            if (matrix[i][j] == target) return true;
        }
    }
    return false;
}

// bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
//     int n = matrix.size(), m = matrix[0].size();
//     int row = 0;
//     int lo = 0, hi = n - 1;
//     while (lo <= hi) {
//         int mid = lo + (hi - lo) / 2;
//         if (target >= matrix[mid][0] && target <= matrix[mid][m - 1]) {
//             row = mid;
//             break;
//         } else if (target < matrix[mid][0]) {
//             hi = mid - 1;
//         } else if (target > matrix[mid][m - 1]) {
//             lo = mid + 1;
//         }
//     }

//     lo = 0, hi = m - 1;
//     while (lo <= hi) {
//         int mid = lo + (hi - lo) / 2;
//         if (target == matrix[row][mid]) return true;
//         else if (target > matrix[row][mid]) lo = mid + 1;
//         else if (target < matrix[row][mid]) hi = mid - 1;
//     }
//     return false;
// }

bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
    if (matrix.empty()) return false;
    int n = matrix.size(), m = matrix[0].size();
    for (int i = 0; i < n; i++) {
        int lo = 0, hi = m - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (matrix[i][mid] == target) return true;
            else if (target > matrix[i][mid]) lo = mid + 1;
            else if (target < matrix[i][mid]) hi = mid - 1;
        }
    }
    return false;
}


// final
bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
    if (matrix.empty()) return false;
    int n = matrix.size(), m = matrix[0].size();
    int i = 0, j = m - 1;
    while (i < n && j >= 0) {
        if (target == matrix[i][j]) return true;
        else if (target > matrix[i][j]) i++;
        else if (target < matrix[i][j]) j--;
    }
    return false;
}