#include <iostream>
#include <vector>
using namespace std;

int minCost(vector<vector<int>>& costs) {
    int n = costs.size();
    if (n == 0) return 0;
    int m = costs[0].size();
    vector<vector<int>> dp(n, vector<int> (m));
    for (int i = 0; i < m; i++) {
        dp[0][i] = costs[0][i];
    }

    for (int i = 1; i < n; i++) {
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + costs[i][0];
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + costs[i][1];
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + costs[i][2];
    }

    return min(dp[n - 1][0], min(dp[n - 1][1], dp[n - 1][2]));
}


// ¿Õ¼äÓÅ»¯
int minCost(vector<vector<int>>& costs) {
    int n = costs.size();
    if (n == 0) return 0;
    vector<int> prev = costs[0];
    for (int i = 1; i < n; i++) {
        vector<int> curr = costs[i];
        curr[0] += min(prev[1], prev[2]);
        curr[1] += min(prev[0], prev[2]);
        curr[2] += min(prev[0], prev[1]);
        prev = curr;
    }
    return min(prev[0], min(prev[1], prev[2]));
}