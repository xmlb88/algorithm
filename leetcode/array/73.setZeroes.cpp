#include <iostream>
#include <vector>
using namespace std;

// 标记数组
// void setZeroes(vector<vector<int>>& matrix) {
//     int m = matrix.size(), n = matrix[0].size();
//     vector<bool> row(m, false), col(n, false);

//     for (int i = 0; i < m; ++i) {
//         for (int j = 0; j < n; ++j) {
//             if (!matrix[i][j]) {
//                 row[i] = col[j] = true;
//             }
//         }
//     }

//     for (int i = 0; i < m; ++i) {
//         for (int j = 0; j < n; ++j) {
//             if (row[i] || col[j]) {
//                 matrix[i][j] = 0;
//             }
//         }
//     }
// }

// 使用2个标记变量，记录第一行第一列的状态
// 将其他行列的状态记录在第一行第一列
// void setZeroes(vector<vector<int>>& matrix) {
//     int n = matrix.size(), m = matrix[0].size();
//     bool row1 = false, col1 = false;

//     for (int i = 0; i < n; ++i) {
//         if (!matrix[i][0]) {
//             col1 = true;
//             break;
//         }
//     }

//     for (int j = 0; j < m; ++j) {
//         if (!matrix[0][j]) {
//             row1 = true;
//             break;
//         }
//     }

//     for (int i = 0; i < n; ++i) {
//         for (int j = 0; j < m; ++j) {
//             if (!matrix[i][j]) {
//                 matrix[i][0] = 0;
//                 matrix[0][j] = 0;
//             }
//         }
//     }

//     for (int i = 1; i < n; ++i) {
//         for (int j = 1; j < m; ++j) {
//             if (!matrix[i][0] || !matrix[0][j]) {
//                 matrix[i][j] = 0;
//             }
//         }
//     }

//     if (col1) {
//         for (int i = 0; i < n; ++i) matrix[i][0] = 0;
//     }

//     if (row1) {
//         for (int j = 0; j < m; ++j) matrix[0][j] = 0;
//     }
// }


// 用一个变量记录第一列
void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    int flag_col0 = false;

    for (int i = 0; i < m; ++i) {
        if (!matrix[i][0]) flag_col0 = true;

        for (int j = 1; j < n; ++j) {
            if (!matrix[i][j]) {
                matrix[i][0] = matrix[0][j] = 0;
            }
        }
    }

    for (int i = m - 1; i >= 0; --i) {
        for (int j = 1; j < n; ++j) {
            if (!matrix[i][0] || !matrix[0][j]) matrix[i][j] = 0;
        }
        if (flag_col0) matrix[i][0] = 0;
    }
}


int main() {
    vector<vector<int>> matrix{
        {0, 1, 2, 0},
        {3, 4, 5, 2},
        {1, 3, 1, 5}
    };

    setZeroes(matrix);
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[0].size(); ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}