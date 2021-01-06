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


//
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    if (n == 0) return 0;
    vector<vector<int>> buy(n, vector<int> (3)), sell(n, vector<int> (3));
    
}