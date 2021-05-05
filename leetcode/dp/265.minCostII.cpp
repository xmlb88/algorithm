#include <iostream>
#include <vector>
using namespace std;

int minCostII(vector<vector<int>>& costs) {
    int n = costs.size();
    if (n == 0) return 0;
    int m = costs[0].size();

    vector<int> prev = costs[0];
    for (int i = 1; i < n; i++) {
        vector<int> curr(m);
        for (int j = 0; j < m; j++) {
            curr[j] = costs[i][j] + minOfLast(prev, j);
        }
        prev = curr;
    }

    return *min_element(prev.begin(), prev.end());
}

int minOfLast(vector<int>& cost, int index) {
    int minCost = INT_MAX;
    for (int i = 0; i < cost.size(); i++) {
        if (i != index) {
            minCost = min(minCost, cost[i]);
        }
    }
    return minCost;
}


// review 2021年5月5日16:02:10
int minValueExcept(vector<int>& dp, int index) {
    int min_val = INT_MAX;
    for (int i = 0; i < dp.size(); ++i) {
        if (i == index) continue;
        min_val = min(min_val, dp[i]);
    }
    return min_val;
}

int minCostII(vector<vector<int>>& costs) {
    int n = costs.size();
    int k = costs[0].size();
    vector<int> dp(costs[0]);
    vector<int> curr(k);
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            curr[j] = costs[i][j] + minValueExcept(dp, j);
        }
        dp = curr;
    }

    int res = INT_MAX;
    for (int num : dp) {
        res = min(res, num);
    }
    return res;
}

// 优化
int minCostII(vector<vector<int>>& costs) {
    int n = costs.size();
    int k = costs[0].size();
    vector<int> dp(costs[0]);
    vector<int> curr(k);
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            vector<int> temp = dp;
            temp[j] = INT_MAX;
            curr[j] = costs[i][j] + *min_element(temp.begin(), temp.end());
        }
        dp = curr;
    }

    int res = INT_MAX;
    for (int num : dp) {
        res = min(res, num);
    }
    return res;
}