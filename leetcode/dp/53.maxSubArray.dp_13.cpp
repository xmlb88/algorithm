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

// �ռ�ѹ���Ż�
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


// review offer 42.
int maxSubArray(vector<int>& nums) {
    // ����dp[i] ����i��β�����������
    int n = nums.size();
    vector<int> dp(n, 0);
    dp[0] = nums[0];
    for (int i = 1; i < n; i++) {
        dp[i] = max(dp[i - 1] + nums[i], nums[i]);
    }

    int res = INT_MIN;
    for (int i = 0; i < n; i++) {
        res = max(res, dp[i]);
    }

    return res;
}

int maxSubArray(vector<int>& nums) {
    int res = nums[0];
    int max_sum = res;
    for (int i = 1; i < nums.size(); i++) {
        max_sum = max(max_sum + nums[i], nums[i]);
        res = max(res, max_sum);
    }

    return res;
}

int maxSubArray(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 0);
    dp[0] = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        dp[i] = max(dp[i - 1] + nums[i], nums[i]);
    }

    int res = INT_MIN;
    for (int i = 0; i < n; i++) {
        res = max(res, dp[i]);
    }

    return res;
}

int maxSubArray(vector<int>& nums) {
    int dp = nums[0];
    int res = dp;
    for (int i = 1; i < nums.size(); i++) {
        dp = max(dp + nums[i], nums[i]);
        res = max(res, dp);
    }

    return res;
}


// review
int maxSubArray(vector<int>& nums) {
    vector<int> dp(nums.size());
    dp[0] = nums[0];
    int max_sum = dp[0];
    for (int i = 1; i < nums.size(); i++) {
        dp[i] = max(nums[i], dp[i - 1] + nums[i]);
        max_sum = max(max_sum, dp[i]);
    }

    return max_sum;
}


// review
int maxSubArray(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n);
    dp[0] = nums[0];
    int res = nums[0];
    for (int i = 1; i < n; ++i) {
        dp[i] = max(dp[i - 1] + nums[i], nums[i]);
        res = max(res, dp[i]);
    }
    return res;
}

int maxSubArray(vector<int>& nums) {
    int n = nums.size();
    int curr = nums[0], res = nums[0];
    for (int i = 1; i < n; ++i) {
        curr = max(curr + nums[i], nums[i]);
        res = max(res, curr);
    }
    return res;
}


// review 2021��1��5��10:13:27
int maxSubArray(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    vector<int> dp(n);
    dp[0] = nums[0];
    for (int i = 1; i < n; i++) {
        dp[i] = max(dp[i - 1] + nums[i], nums[i]);
    }

    return *max_element(dp.begin(), dp.end());
}

// ���Ϳռ临�Ӷ�
int maxSubArray(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    int curr = nums[0], res = nums[0];
    for (int i = 1; i < n; i++) {
        curr = max(curr + nums[i], nums[i]);
        res = max(res, curr);
    }
    return res;
}