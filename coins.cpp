// dp数组迭代
int coinChange(vector<int>& coins, int amount) {
    // 数组大小为amount + 1，初始值也为amount + 1
    vector<int> dp(amount + 1, amount + 1);
    // base case
    dp[0] = 0;
    // 外层for循环遍历所有状态取值
    for (int i = 0; i < dp.size(); i++) {
        // 内层for循环求所有选择最小值
        for (coin in coins) {
            // 子问题无解，跳过
            if (i - coin < 0) continue;
            dp[i] = min(dp[i], 1 + dp[i - coin]);
        }
    }
    return (dp[amount] == amount + 1)? -1 : dp[amount];
}