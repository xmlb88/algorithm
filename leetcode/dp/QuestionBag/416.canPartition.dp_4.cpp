#include<iostream>
#include<vector>
using namespace std;

bool canPartition(vector<int>& nums) {
    int sum = 0;
    for (int num : nums) sum += num;

    if (sum % 2 != 0) return false;

    int n = nums.size();
    sum = sum / 2;

    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));

    for (int i = 0; i <= n; i++) {
        dp[i][0] = true;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (j - nums[i - 1] < 0) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
            }
        }
    }

    return dp[n][sum];

}

bool canPartition(vector<int>& nums) {
    int sum = 0;
    for (int num : nums) sum += num;
    if (sum % 2 != 0) return false;

    int n = nums.size();
    sum = sum / 2;

    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));
    for (int i = 0; i <= n; i++) dp[i][0] = true;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (j - nums[i - 1] < 0) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
            }
        }
    }

    return dp[n][sum];
}

bool canPartition(vector<int>& nums) {
    int sum = 0;
    for (int num : nums) sum += num;

    if (sum % 2 != 0) return false;
    int n = nums.size();
    sum /= 2;
    vector<bool> dp(sum + 1, false);
    dp[0] = true;
    for (int i = 0; i < n; i++) {
        for (int j = sum; j >= 0; j--) {
            if (j - nums[i] >= 0) {
                dp[j] = dp[j] || dp[j - nums[i]];
            } 
        }
    }

    return dp[sum];
}


// review 2021年6月15日15:40:47
// 0-1背包

bool canPartition(vector<int>& nums) {
    int n = nums.size();
    int sum = 0;
    for (int num : nums) sum += num;
    if (sum % 2) return false;
    sum = sum / 2;
    vector<vector<int>> dp(n + 1, vector<int> (sum + 1, 0));

    for (int i = 0; i <= n; ++i) dp[i][0] = 1;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= sum; ++j) {
            if (nums[i - 1] > j) dp[i][j] = dp[i - 1][j];
            else {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
            }
        }
    }
    return dp[n][sum];
}

// 空间优化

bool canPartition(vector<int>& nums) {
    int n = nums.size();
    int sum = 0;
    for (int num : nums) sum += num;
    if (sum % 2) return false;
    sum = sum / 2;

    vector<int> dp(sum + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; ++i) {
        for (int j = sum; j >= 1; --j) {
            if (j >= nums[i - 1]) dp[j] = dp[j] || dp[j - nums[i - 1]];
        }
    }
    return dp[sum];
}