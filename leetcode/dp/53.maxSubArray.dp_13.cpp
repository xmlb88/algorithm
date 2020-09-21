#include <iostream>
#include <vector>
using namespace std;

int maxSubArray(vector<int>& nums) {
    vector<int>dp(nums.size(), 0);
    dp[0] = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        dp[i] = max(dp[i - 1] + nums[i], nums[i]);
    }

    int s = INT_MIN;
    for (int sum : dp) {
        s = max(s, sum);
    }

    return s;
}

// ¿Õ¼äÑ¹ËõÓÅ»¯
int maxSubArray(vector<int>& nums) {
    if (nums.size() == 0) return 0;
    int dp = nums[0];
    int max_sum = dp;

    for (int i = 1; i < nums.size(); i++) {
        dp = max(dp + nums[i], nums[i]);
        max_sum = max(max_sum, dp);
    }

    return max_sum;
}