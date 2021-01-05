#include<iosteram>
#include<vector>
using namespace std;

// dp数组迭代
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

// dp数组迭代 + 状态压缩
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

// 递归
int rob(vector<int>& nums) {
    return dp(nums, 0);
}

int dp(vector<int>& nums, int start) {
    if (start >= nums.size()) return 0;

    int res = max(dp(nums, start + 1), nums[start] + dp(nums, start + 2));

    return res;
}

// 备忘录递归

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

// review 2021年1月5日20:43:43
int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    if (n == 1) return nums[0];
    vector<int> dp(n);
    dp[0] = nums[0], dp[1] = max(nums[0], nums[1]);
    for (int i = 2; i < n; i++) {
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
    }

    return dp[n - 1];
}

// 优化空间
int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    if (n == 1) return nums[0];
    int prev = nums[0], curr = max(nums[0], nums[1]);
    for (int i = 2; i < n; i++) {
        int temp = max(curr, prev + nums[i]);
        prev = curr;
        curr = temp;
    }
    return curr;
}