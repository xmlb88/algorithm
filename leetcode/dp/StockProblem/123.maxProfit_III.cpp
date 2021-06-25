#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    if (n == 0) return 0;
    vector<vector<int>> buy(n, vector<int> (3)), sell(n, vector<int> (3));
    buy[0][0] = -prices[0], buy[0][1] = INT_MIN / 2, buy[0][2] = INT_MIN / 2;
    sell[0][0] = 0, sell[0][1] = INT_MIN / 2, sell[0][2] = INT_MIN / 2;
    for (int i = 1; i < n; i++) {
        buy[i][0] = max(buy[i - 1][0], sell[i - 1][0] - prices[i]);
        for (int j = 1; j <= 2; j++) {
            buy[i][j] = max(buy[i - 1][j], sell[i - 1][j] - prices[i]);
            sell[i][j] = max(sell[i - 1][j], buy[i - 1][j - 1] + prices[i]);
        }
    }

    return *max_element(sell[n - 1].begin(), sell[n - 1].end());
}


// dp[i][k][0] 第i天最多进行k次交易次数未持有股票最大利润 dp[i][k][1] 第i天最多进行k次交易次数持有股票最大利润
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>> (3, vector<int> (2)));

    // dp[i][0][0] = 0
}

/**
 * 到最后交易结束时，一共会有5种状态：

dp0：一直不买
dp1：到最后也只买入了一笔
dp2：到最后买入一笔，卖出一笔
dp3：到最后买入两笔，卖出一笔
dp4：到最后买入两笔，卖出两笔

初始化5种状态：

dp0 = 0
dp1 = - prices[0]
因为第一天不可能会有dp2，dp3，dp4三种状态，因此将这三者置为负无穷(Java中置为int的下边界)
dp2 = float("-inf")
dp3 = float("-inf")
dp4 = float("-inf")

对5种状态进行状态转移。

dp0 = 0
#一直为0
dp1 = max(dp1, dp0 - prices[i])
#前一天也是dp1状态，或者前一天是dp0状态，今天买入一笔变成dp1状态
dp2 = max(dp2, dp1 + prices[i])
#前一天也是dp2状态，或者前一天是dp1状态，今天卖出一笔变成dp2状态
dp3 = max(dp3, dp2 - prices[i])
#前一天也是dp3状态，或者前一天是dp2状态，今天买入一笔变成dp3状态
dp4 = max(dp4, dp3 + prices[i])
#前一天也是dp4状态，或者前一天是dp3状态，今天卖出一笔变成dp4状态

最后一定是手里没有股票赚的钱最多，但不一定交易次数越多赚得越多，应该要返回dp0，dp2，dp4的最大值；但是我代码的写法中其实允许了同一天买入卖出的，只不过因为一天的价格不变而不会对结果有影响，因此最大值是必然会转移到dp4的，所以只要返回dp4就可以了

*/

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    if (n < 2) return 0;
    int dp_0 = 0, dp_1 = -prices[0], dp_2 = INT_MIN, dp_3 = INT_MIN, dp_4 = INT_MIN;

    for (int i = 1; i < n; ++i) {
        dp_1 = max(dp_1, dp_0 - prices[i]);
        dp_2 = max(dp_2, dp_1 + prices[i]);
        dp_3 = max(dp_3, dp_2 - prices[i]);
        dp_4 = max(dp_4, dp_3 + prices[i]);
    }

    return dp_4;
}