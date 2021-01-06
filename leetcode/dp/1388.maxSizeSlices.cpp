#include <iostream>
#include <vector>
using namespace std;

int maxSizeSlices(vector<int>& slices) {
    if (slices.empty()) return 0;
    vector<int> slices1(slices.begin(), slices.end() - 1);
    vector<int> slices2(slices.begin() + 1, slices.end());
    return max(maxSize(slices1), maxSize(slices2));
}

int maxSize(vector<int>& nums) {
    int n = nums.size(), m = n / 3 + 1;
    vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));
    dp[1][1] = nums[0];
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i - 2][j - 1] + nums[i - 1]);
        }
    }
    return dp[n][m];
}