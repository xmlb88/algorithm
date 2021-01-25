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