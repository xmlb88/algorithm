#include<iostream>
#include<vector>
using namespace std;

int maxProfit(vector<int>& prices) {
    int min_value = INT_MAX, profit = 0;
    for (int i = 0; i < prices.size(); i++) {
        min_value = min(min_value, prices[i]);
        profit = max(profit, prices[i] - min_value);
    }

    return profit;
}

// int maxProfit(vector<int>& prices) {
//     int min_value = INT_MAX, profit = 0;
//     for (int i = 0; i < prices.size(); i++) {
//         min_value = min(min_value, prices[i]);
//         profit = max(profit, prices[i] - min_value);
//     }

//     return profit;
// }


// review 2021年6月25日15:10:48

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    int min_price = INT_MAX;
    int max_profit = 0;
    for (int i = 0; i < n; ++i) {
        min_price = min(min_price, prices[i]);
        max_profit = max(max_profit, prices[i] - min_price);
    }
    return max_profit;
}


// dp[i][0] 第i天未持有股票时最大收益 dp[i][1]第i天持有股票最大收益
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int> (2));
    dp[0][1] = -prices[0];
    dp[0][0] = 0;

    for (int i = 1; i < n; ++i) {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
        dp[i][1] = max(dp[i - 1][1], - prices[i]);
    }

    return dp[n - 1][0];
}

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    int dp_i_0 = 0, dp_i_1 = -prices[0];

    for (int i = 1; i < n; ++i) {
        dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
        dp_i_1 = max(dp_i_1, -prices[i]);
    }
    return dp_i_0;
}