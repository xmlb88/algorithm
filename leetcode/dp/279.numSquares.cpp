#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// dfs

int dfs(int n, vector<int>& memo) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    if (memo[n] != -1) return memo[n];
    int num = sqrt(n);
    long res = INT_MAX;

    for (int i = num; i >= 1; --i) {
        if (i * i > n) continue;
        res = min(res, static_cast<long>(dfs(n - i * i, memo)) + 1);
    }
    memo[n] = res;
    return memo[n];
}

int numSquares(int n) {
    vector<int> memo(n + 1, -1);
    return dfs(n, memo);
}

// dp
int numSquares(int n) {
    vector<int> dp(n + 1);
    for (int i = 1; i <= n; ++i) {
        int minn = INT_MAX;
        for (int j = 1; j * j <= i; ++j) {
            minn = min(minn, dp[i - j * j] + 1);
        }
        dp[i] = minn;
    }
    return dp[n];
}