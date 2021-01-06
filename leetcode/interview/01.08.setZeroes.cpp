#include <iostream>
#include <vector>
using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
    int n = matrix.size();
    // if (n == 0) return;
    int m = matrix[0].size();
    // if (m == 0) return;

    vector<pair<int, int>> zero;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) zero.push_back({i, j});
        }
    }

    for (auto kv : zero) {
        for (int j = 0; j < m; j++)
            matrix[kv.first][j] = 0;

        for (int i = 0; i < n; i++)
            matrix[i][kv.second] = 0;
    }
}

void setZeroes(vector<vector<int>>& matrix) {
    int n = matrix.size(), m = matrix[0].size();
    bool rowHasZero = false, colHasZero = false;
    
    for (int j = 0; j < m; j++) {
        if (matrix[0][j] == 0) {
            rowHasZero = true;
            break;
        }
    }

    for (int i = 0; i < n; i++) {
        if (matrix[i][0] == 0) {
            colHasZero = true;
            break;
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    for (int j = 1; j < m; j++) {
        if (matrix[0][j] == 0) {
            for (int i = 1; i < n; i++) {
                matrix[i][j] = 0;
            }
        }
    }

    for (int i = 1; i < n; i++) {
        if (matrix[i][0] == 0) {
            for (int j = 1; j < m; j++) {
                matrix[i][j] = 0;
            }
        }
    }

    if (rowHasZero) {
        for(int j = 0; j < m; j++) {
            matrix[0][j] = 0;
        }
    }

    if (colHasZero) {
        for (int i = 0; i < n; i++) {
            matrix[i][0] = 0;
        }
    }
}