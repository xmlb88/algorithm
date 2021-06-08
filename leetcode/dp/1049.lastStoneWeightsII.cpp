#include <iostream>
#include <vector>
using namespace std;

// 31 26 33 21 40
// TODO:
int lastStoneWeightII(vector<int>& stones) {
    int n = stones.size();
    int sum = 0;
    for (int num : stones) sum += num;

    int capacity = sum >> 1;
    vector<vector<int>> dp(n + 1, vector<int> (capacity + 1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= capacity; ++j) {
            if (j >= stones[i - 1]) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - stones[i - 1]] + stones[i - 1]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return (sum - dp[n][capacity]) - dp[n][capacity];
}