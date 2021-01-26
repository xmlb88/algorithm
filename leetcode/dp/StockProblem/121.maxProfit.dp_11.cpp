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