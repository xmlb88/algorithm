#include <iostream>
#include <vector>
using namespace std;

int helper(vector<int>& coins, int amount, vector<int>& memo) {
    // base case
    if (amount == 0) return 0;
    if (amount < 0) return -1;

    //查备忘录
    if (memo[amount] != INT_MAX) return memo[amount];

    //未查到
    int res = INT_MAX;
    for (int coin : coins) {
        int pre = helper(coins, amount - coin, memo);
        /* if (pre == -1) continue;
        res = min(res, 1 + pre); */

        if (pre >= 0 && pre < res) {
            res = 1 + pre;
        }
    }

    memo[amount] = (res == INT_MAX)? -1:res;
    return memo[amount];
}

int coinChange(vector<int>& coins, int amount) {
    vector<int> memo(amount + 1, INT_MAX);
    return helper(coins, amount, memo);
}

int main() {
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    cout << coinChange(coins, amount);
}