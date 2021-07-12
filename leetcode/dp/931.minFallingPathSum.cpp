#include <iostream>
#include <vector>
using namespace std;

int minFallingPathSum(vector<vector<int>>& matrix) {
    int n = matrix.size(), m = matrix[0].size();
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int last_min_number = matrix[i - 1][j];
            if (j - 1 >= 0) {
                last_min_number = min(last_min_number, matrix[i - 1][j - 1]);
            }
            if (j + 1 < m) {
                last_min_number = min(last_min_number, matrix[i - 1][j + 1]);
            }

            matrix[i][j] += last_min_number;
        }
    }

    return *min_element(matrix.back().begin(), matrix.back().end());
}