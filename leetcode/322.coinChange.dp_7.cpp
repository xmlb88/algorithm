#include<iostream>
#include<vector>
#include<string>
using namespace std;

unordered_map<int, int> dp;
int coinChange(vector<int>& coins, int amount) {
    // int result = INT_MAX;
    return backtrace(coins, amount);
}

int backtrace(vector<int>& coins, int amount) {
    if (amount == 0) return 0;
    if (amount < 0) return -1;
    if (dp.count(amount)) return dp[amount];

    int result = INT_MAX;
    for (int i = 0; i < coins.size(); i++) {
        int res = backtrace(coins, amount - coins[i]);
        if (res == -1) continue;
        result = min(result, res + 1);
    }

    dp[amount] = result == INT_MAX? -1 : result;
    return dp[amount];
}



//dp
int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;

    for (int i = 0; i < dp.size(); i++) {
        for (int coin : coins) {
            if (i - coin < 0) continue;
            dp[i] = min(dp[i], 1 + dp[i - coin]);
        }
    }

    return dp[amount] == amount + 1? -1 : dp[amount];
}