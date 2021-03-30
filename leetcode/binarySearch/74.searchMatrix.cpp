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


// 二分
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size(), n = matrix[0].size();
    int left = 0, right = m * n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int x = mid / n, y = mid % n;
        if (matrix[x][y] == target) return true;
        else if (matrix[x][y] < target) left = mid + 1;
        else right = mid - 1;
    }
    return false;
}

// 从右上角搜索
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix.size(), m = matrix[0].size();
    int x = 0, y = m - 1;
    while (x < n && y >= 0) {
        if (matrix[x][y] == target) return true;
        else if (matrix[x][y] > target) --y;
        else if (matrix[x][y] < target) ++x;
    }
    return false;
}

// 从左下角搜索
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix.size(), m = matrix[0].size();
    int x = n - 1, y = 0;
    while (x >= 0 && y < m) {
        if (matrix[x][y] == target) return true;
        else if (matrix[x][y] > target) --x;
        else if (matrix[x][y] < target) ++y;
    }
    return false;
}

// 2次二分查找
// https://leetcode-cn.com/problems/search-a-2d-matrix/solution/sou-suo-er-wei-ju-zhen-by-leetcode-solut-vxui/
// 

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    auto row = upper_bound(matrix.begin(), matrix.end(), target, [] (const int b, const vector<int>& a) {
        return b < a[0];
    });

    if (row == matrix.begin()) return false;

    --row;
    return binary_search(row -> begin(), row -> end(), target);
}