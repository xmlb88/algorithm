

int integerBreak(int n) {
    vector<int> dp(n + 1, 0);

    for (int i = 2; i <= n; i++) {
        int curMax = 0;
        for (int j = 1 ; j < i; j++) {
            curMax = max(curMax, max(j * (i - j), j * dp[i - j]));
        }
        dp[i] = curMax;
    }

    return dp[n];
}

/* 
定义dp[i] : 对i进行拆分出j，此时乘积 = i * (i - j)， i - j 可以继续拆分，也可以不拆
状态转移：dp[i] = max(j * (i - j), j * dp[i - j])
base case : dp[0] = dp[1] = 1
 */