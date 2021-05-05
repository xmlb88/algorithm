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


// 空间优化
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

// review

int minCost(vector<vector<int>>& costs) {
    int n = costs.size();
    if (n == 0) return 0;
    vector<vector<int>> dp(n, vector<int>(3));
    dp[0] = costs[0];
    for (int i = 1; i < n; i++) {
        dp[i][0] = costs[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
        dp[i][1] = costs[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
        dp[i][2] = costs[i][2] + min(dp[i - 1][0], dp[i - 1][1]);
    }

    return min(dp[n - 1][0], min(dp[n - 1][1], dp[n - 1][2]));
}

// 空间优化
int minCost(vector<vector<int>>& costs) {
    int n = costs.size();
    if (n == 0) return 0;
    vector<int> prev = costs[0];
    for (int i = 1; i < n; i++) {
        vector<int> curr(3);
        curr[0] = costs[i][0] + min(prev[1], prev[2]);
        curr[1] = costs[i][1] + min(prev[0], prev[2]);
        curr[2] = costs[i][2] + min(prev[0], prev[1]);
        prev = curr;
    }

    return min(prev[0], min(prev[1], prev[2]));
}


// review 2021年5月5日15:44:40
int minCost(vector<vector<int>>& cost) {
    int n = cost.size();
    vector<vector<int>> dp(n, vector<int> (3));
    dp[0] = cost[0];
    for (int i = 1; i < n; ++i) {
        dp[i][0] = cost[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
        dp[i][1] = cost[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
        dp[i][2] = cost[i][2] + min(dp[i - 1][0], dp[i - 1][1]);
    }

    return min(dp[n - 1][0], min(dp[n - 1][1], dp[n - 1][2]));
}

// 空间优化
int minCost(vector<vector<int>>& costs) {
    int n = costs.size();
    vector<int> dp(costs[0]);
    vector<int> curr(3);
    for (int i = 1; i < n; ++i) {
        curr[0] = costs[i][0] + min(dp[1], dp[2]);
        curr[1] = costs[i][1] + min(dp[0], dp[2]);
        curr[2] = costs[i][2] + min(dp[0], dp[1]);
        dp = curr;
    }
    return min(dp[0], min(dp[1], dp[2]));
}