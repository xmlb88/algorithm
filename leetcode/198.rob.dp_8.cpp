#include<iosteram>
#include<vector>
using namespace std;

// dpÊı×éµü´ú
int rob(vector<int>& nums) {
    if (nums.size() == 0) return 0;
    if (nums.size() == 1) return nums[0];
    vector<int> dp(nums.size(), 0);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    for (int i = 2; i < nums.size(); i++) {
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
    }

    return dp[nums.size() - 1];
}

// dpÊı×éµü´ú + ×´Ì¬Ñ¹Ëõ
int rob(vector<int>& nums) {
    if (nums.size() == 0) return 0;
    if (nums.size() == 1) return nums[0];

    int dp_1 = nums[0];
    int dp_2 = max(nums[0], nums[1]);

    int result = dp_2;
    for (int i = 2; i < nums.size(); i++) {
        result = max(dp_2, dp_1 + nums[i]);
        dp_1 = dp_2;
        dp_2 = result;
    }

    return result;
}

// µİ¹é
int rob(vector<int>& nums) {
    return dp(nums, 0);
}

int dp(vector<int>& nums, int start) {
    if (start >= nums.size()) return 0;

    int res = max(dp(nums, start + 1), nums[start] + dp(nums, start + 2));

    return res;
}

// ±¸ÍüÂ¼µİ¹é

vector<int> memo;
int rob(vector<int>& nums) {
    memo.resize(nums.size(), -1);
    return dp(nums, 0);
}

int dp(vector<int>& nums, int start) {
    if (start >= nums.size()) return 0;

    if (memo[start] != -1) return memo[start];

    memo[start] = max(dp(nums, start + 1), nums[start] + dp(nums, start + 2));
    return memo[start];
}