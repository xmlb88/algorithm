#include <iostream>
#include <vector>
using namespace std;

int integerBreak(int n) {
    if (n == 1) return 0;
    if (n == 2) return 1;
    if (n == 3) return 2;
    int res = -1;
    for (int i = 1; i <= n - 1; i++) {
        res = max(res, max(i * (n - i), i * integerBreak(n - i)));
    }
    return res;
}

// ±¸ÍüÂ¼ÓÅ»¯
vector<int> memo;
int integerBreak(int n) {
    memo.assign(n + 1, -1);
    return integerDp(n);
}

int integerDp(int n) {
    if (n == 2) return 1;
    if (memo[n] != -1) return memo[n];
    int res = -1;
    for (int i = 1; i < n; i++) {
        res = max(res, max(i * (n - i), i * integerDp(n - i)));
    }
    memo[n] = res;
    return res;
}

// dp
int integerBreak(int n) {
    vector<int> dp(n + 1, 0);
    for (int i = 2; i <= n; i++) {
        int curMax = 0;
        for (int j = 1; j < i; j++) {
            curMax = max(curMax, max(j * (i - j), dp[i - j] * j));
        }
        dp[i] = curMax;
    }
    return dp[n];
}