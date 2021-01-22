#include <iostream>
#include <vector>
using namespace std;

double largestSumOfAverages(vector<int>& A, int K) {
    int n = A.size();
    // 前缀和
    vector<double> preSum(n + 1);
    for (int i = 1; i <= n; i++) {
        preSum[i] = preSum[i - 1] + A[i - 1];
    }
    
    vector<vector<double>> dp(n, vector<double>(K));
    for (int i = 1; i <= n; i++) {
        dp[i - 1][0] = preSum[i] / i;
    }

    for (int k = 1; k < K; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++)
                dp[i][k] = max(dp[i][k], (preSum[i + 1] - preSum[j + 1]) / (i - j) + dp[j][k - 1]);
        }
    }

    return dp[n - 1][K - 1];
}


// 空间优化
double largestSumOfAverages(vector<int>& A, int K) {
    int n = A.size();

    vector<double> preSum(n + 1);
    for (int i = 0; i < n; i++) {
        preSum[i + 1] = preSum[i] + A[i];
    }

    vector<double> dp(n);
    for (int i = 0; i < n; i++) {
        dp[i] = preSum[i + 1] / (i + 1);
    }

    for (int k = 1; k < K; k++) {
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < i; j++) {
                dp[i] = max(dp[i], dp[j] + (preSum[i + 1] - preSum[j + 1]) / (i - j));
            }
        }
    }
    return dp[n - 1];
}