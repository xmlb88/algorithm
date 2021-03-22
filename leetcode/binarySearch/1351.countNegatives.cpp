#include <iostream>
#include <vector>
using namespace std;

int countNegatives(vector<vector<int>>& grid) {
    int count = 0;
    int n = grid.size(), m = grid[0].size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] < 0) ++count;
        }
    }
    return count;
}

// 二分
// 4 3 2 1 -1 -2 : 0 6
// 3, 6, mid = 4
// 3 4 mid = 3
int rowNegatives(vector<int>& row) {
    int left = 0, right = row.size();
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (row[mid] >= 0) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return row.size() - left;
}

int countNegatives(vector<vector<int>>& grid) {
    int count = 0;
    for (auto& vec : grid) {
        count += rowNegatives(vec);
    }
    return count;
}


// 从右上角开始遍历
int countNegatives(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    int count = 0;
    for (int i = 0, j = m - 1; i < n && j >= 0; ) {
        if (grid[i][j] >= 0) {
            ++i;
        } else if (grid[i][j] < 0) {
            count += n - i;
            --j;
        }
    }
    return count;
}