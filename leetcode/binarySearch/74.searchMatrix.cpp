#include <iostream>
#include <vector>
using namespace std;

bool searchRow(vector<vector<int>>& matrix, int row, int target) {
    int left = 0, right = matrix[row].size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (matrix[row][mid] == target) return true;
        if (matrix[row][mid] < target) {
            left = mid + 1;
        } else if (matrix[row][mid] > target) {
            right = mid - 1;
        }
    }
    return false;
}

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.empty()) return false;
    int left = 0, right = matrix.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (matrix[mid][0] == target) return true;
        if (matrix[mid][0] < target) {
            left = mid + 1;
        } else if (matrix[mid][0] > target) {
            right = mid - 1;
        }
    }
    if (right < 0 || right >= matrix.size()) return false;
    return searchRow(matrix, right, target);
}

int main() {
    // vector<vector<int>> matrix = {
    //     {1, 3, 5, 7},
    //     {10, 11, 16, 20},
    //     {23, 30, 34, 60}
    // };
    vector<vector<int>> matrix = {{1}};

    int target = 2;
    cout << searchMatrix(matrix, target) << endl;
}

// 转化为一维数组
// 索引0， mn -1
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.empty()) return false;
    int n = matrix.size(), m = matrix[0].size();
    int left = 0, right = n * m - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (matrix[mid / m][mid % m] == target) return true;

        if (matrix[mid / m][mid % m] < target) {
            left = mid + 1;
        } else if (matrix[mid / m][mid % m] > target) {
            right = mid - 1;
        }
    }
    return false;
}