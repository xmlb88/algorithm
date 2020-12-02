#include <iostream>
#include <vector>
using namespace std;

// 
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            if (matrix[i][j] == target) return true;
        }
    }
    return false;
}

// 每行二分OM(logN)
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    if (m == 0) return false;
    int n = matrix[0].size();
    for (int i = 0; i < m; i++) {
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (target == matrix[i][mid]) return true;
            else if (target > matrix[i][mid]) left = mid + 1;
            else if (target < matrix[i][mid]) right = mid - 1;
        }
    }
    return false;
}

// 右上角开始，小于左移，大于下移 O(M + N)
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.empty()) return false;
    int m = matrix.size(), n = matrix[0].size();
    int row = 0, col = n - 1;
    while (row < m && col >= 0) {
        if (matrix[row][col] == target) return true;
        else if (matrix[row][col] < target) row++;
        else if (matrix[row][col] > target) col--;;
    }
    return false;
}

// 二分