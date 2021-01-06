#include <iostream>
#include <vector>
using namespace std;

int deleteAndEarn(vector<int>& nums) {
    if (nums.empty()) return 0;
    if (nums.size() == 1) return nums[0];
    int n = *max_element(nums.begin(), nums.end());
    vector<int> count(n + 1, 0);
    for (int num : nums) {
        count[num]++;
    }

    vector<int> dp(n + 1, 0);
    dp[0] = 0, dp[1] = count[1];
    for (int i = 2; i <= n; i++) {
        dp[i] = max(dp[i - 1], dp[i - 2] + count[i] * i);
    }

    return dp[n];
}

int deleteAndEarn(vector<int>& nums) {
    if (nums.empty()) return 0;
    if (nums.size() == 1) return nums[0];
    int n = *max_element(nums.begin(), nums.end());
    vector<int> count(n + 1, 0);
    for (int num : nums) {
        count[num]++;
    }

    int dp_1 = 0, dp_2 = count[1];
    for (int i = 2; i <= n; i++) {
        int temp = max(dp_2, dp_1 + i * count[i]);
        dp_1 = dp_2;
        dp_2 = temp;
    }

    return dp_2;
}