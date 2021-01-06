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

// ¿Õ¼äÓÅ»¯
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