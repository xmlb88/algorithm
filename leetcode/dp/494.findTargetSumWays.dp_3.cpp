#include<iostream>
#include<vector>
using namespace std;

// int result = 0;
// int findTargetSumWays(vector<int>& nums, int S) {
//     if (nums.size() == 0) return 0;
//     backtrace(nums, 0, S);
//     return result;
// }

// void backtrace(vector<int>& nums, int i, int rest) {
//     if (i == nums.size()) {
//         if (rest == 0) {
//             result++;
//         }
//         return;
//     }

//     rest += nums[i];
//     backtrace(nums, i + 1, rest);
//     rest -= nums[i];

//     rest -= nums[i];
//     backtrace(nums, i + 1, rest);
//     rest += nums[i];
// }

// int findTargetSumWays(vector<int>& nums, int S) {
//     if (nums.size() == 0) return 0;
//     return backtrace(nums, 0, S);
// }

// unordered_map<string, int> memo;
// int backtrace(vector<int>& nums, int i, long long rest) {
//     if (i == nums.size()) {
//         if (rest == 0) {
//             return 1;
//         }

//         return 0;
//     }

//     string key = to_string(i) + "," + to_string(rest);
//     if (memo.count(key)) {
//         return memo[key];
//     }

//     int result = backtrace(nums, i + 1, rest - nums[i]) + backtrace(nums, i + 1, rest + nums[i]);
//     memo[key] = result;
//     return result;
// }

int subsets(vector<int>& nums, int sum) {
    int n = nums.size();
    vector<int> dp(sum + 1);
    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = sum; j >= 0; j--) {
            if (j >= nums[i - 1]) {
                dp[j] = dp[j] + dp[j - nums[i - 1]];
            } else {
                dp[j] = dp[j];
            }
        }
    }

    return dp[sum];
}

int findTargetSumWays(vector<int>& nums, int S) {
    int sum = 0;
    for (int n : nums) sum += n;

    if (sum < S || (sum + S) % 2 == 1) {
        return 0;
    }

    return subsets(nums, (sum + S) / 2);

}