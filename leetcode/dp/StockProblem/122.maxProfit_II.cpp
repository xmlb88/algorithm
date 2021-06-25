#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    if (n == 0) return 0;
    vector<int> buy(n), sell(n);
    buy[0] = -prices[0];
    sell[0] = 0;
    for (int i = 1; i < n; i++) {
        buy[i] = max(buy[i - 1], sell[i - 1] - prices[i]);
        sell[i] = max(sell[i - 1], buy[i - 1] + prices[i]);
    }

    return sell[n - 1];
}

// 空间优化
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    if (n == 0) return 0;
    int buy = -prices[0], sell = 0;
    for (int i = 1; i < n; i++) {
        int newBuy = max(buy, sell - prices[i]);
        int newSell = max(sell, buy + prices[i]);
        buy = newBuy;
        sell = newSell;
    }

    return sell;
}

// review 2021年6月25日16:39:14

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    if (n == 0) return 0;
    vector<vector<int>> dp(n, vector<int> (2));
    dp[0][1] = -prices[0];
    dp[0][0] = 0;

    for (int i = 1; i < n; ++i) {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
    }

    return dp[n - 1][0];
}


int maxProfit(vector<int>& prices) {
    int n = prices.size();
    int dp_i_0 = 0, dp_i_1 = -prices[0];

    for (int i = 1; i < n; ++i) {
        int temp = dp_i_0;
        dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
        dp_i_1 = max(dp_i_1, temp - prices[i]);
    }

    return dp_i_0;
}

// 可用贪心算法
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    int max_profit = 0;
    for (int i = 0; i < n - 1; ++i) {
        int diff = prices[i + 1] - prices[i];
        if (diff > 0) max_profit += diff;
    }
    return max_profit;
}