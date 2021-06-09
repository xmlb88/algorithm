#include <iostream>
#include <vector>
using namespace std;

int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
    int n = matrix.size(), m = matrix[0].size();
    vector<vector<int>> dp (n + 1, vector<int> (m + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + matrix[i - 1][j - 1];
        }
    }

    int num = 0;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            for (int k = 0; k <= n; ++k) {
                for (int q = 0; q <= m; ++q) {
                    if (dp[k][q] - dp[i][j] == target) ++num;
                }
            }
        }
    }
    return num;
}