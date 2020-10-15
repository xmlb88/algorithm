#include<iostream>
#include<vector>
using namespace std;

int coinChange(vector<int>& coins, int amount) {
    int res = INT_MAX;
    return helper(coins, amount, res);
}

int helper(vector<int>& coins, int amount, int res) {
    if (amount == 0) return 0;
    if (amount < 0) return -1;

    for (int i = 0; i < coins.size(); i++) {
        // if (amount - coins[i] < 0) continue;
        int n = helper(coins, amount - coins[i], res);
        if (n == -1) continue;
        res = min(res, n + 1);
    }

    return res == INT_MAX? -1 : res;
}

// coins = {1, 2, 5};
// amount = 11;

// dp数组迭代
int coinChange(vector<int>& coins, int amount) {
    // 数组大小为amount + 1，初始值也为amount + 1
    vector<int> dp(amount + 1, amount + 1);
    // base case 
    dp[0] = 0;
    // 外层for循环遍历所有状态的所有取值
    for (int i = 0; i < dp.size(); i++) {
        for (int coin : coins) {
            // 子问题无解，跳过
            if (i - coin < 0) continue;
            dp[i] = min(dp[i], 1 + dp[i - coin]);
        }
    }

    return (dp[amount] == amount + 1) ? -1 : dp[amount];
}


// review
int coinChange(vector<int>& coins, int amount) {
    if (amount == 0) return 0;
    if (amount < 0) return -1;
    int res = INT_MAX;
    for (int coin : coins) {
        int subproblem = coinChange(coins, amount - coin);
        if (subproblem == -1) continue;
        res = min(res, subproblem + 1);
    }

    return res == INT_MAX? -1 : res;
}

