#include <iostream>
#include <vector>
using namespace std;

int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();
    if (n == 0) return 0;
    vector<int> dp(n);
    dp[0] = cost[0];
    dp[1] = cost[1];
    for (int i = 2; i < n; i++) {
        dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
    }

    return min(dp[n - 1], dp[n - 2]);
}

// 
int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();
    vector<int> dp(n + 1);
    dp[0] = dp[1] = 0;
    for (int i = 2; i <= n; i++) {
        dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
    }
    return dp[n];
}

int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();
    vector<int> dp(n + 1);
    dp[0] = dp[1] = 0;
    for (int i = 2; i <= n; i++) {
        dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
    }
    return dp[n];
}

int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();
    int prev = 0, curr = 0;
    for (int i = 2; i <= n; i++) {
        int temp = min(prev + cost[i - 2], curr + cost[i - 1]);
        prev = curr;
        curr = temp;
    }

    return curr;
}