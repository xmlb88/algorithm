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

int deleteAndEarn(vector<int>& nums) {
    int n = *max_element(nums.begin(), nums.end());
    vector<int> count(n + 1, 0);
    for (int num : nums) {
        count[num]++;
    }

    vector<int> dp(n + 1, 0);
    dp[0] = 0, dp[1] = count[1];
    for (int i = 2; i <= n; ++i) {
        dp[i] = max(dp[i - 1], dp[i - 2] + i * count[i]);
    }
    return dp[n];
}



int deleteAndEarn(vector<int>& nums) {
    int n = *max_element(nums.begin(), nums.end());
    vector<int> count(n + 1, 0);
    for (int num : nums) {
        count[num]++;
    }
    vector<int> dp(n + 1, 0);
    dp[0] = 0, dp[1] = count[1];
    for (int i = 2; i <= n; ++i) {
        dp[i] = max(dp[i - 1], dp[i - 2] + i * count[i]);
    }
    return dp[n];
}

int deleteAndEarn(vector<int>& nums) {
    int n = *max_element(nums.begin(), nums.end());
    vector<int> count(n + 1, 0);
    for (int num : nums) {
        count[num]++;
    }
    
    int dp_1 = 0, dp_2 = count[1];
    for (int i = 2; i <= n; ++i) {
        int dp = max(dp_2, dp_1 + i * count[i]);
        dp_1 = dp_2;
        dp_2 = dp;
    }
    return dp_2;
}


// https://leetcode-cn.com/problems/delete-and-earn/solution/shan-chu-bing-huo-de-dian-shu-by-leetcod-x1pu/
// 

int deleteAndEarn(vector<int>& nums) {
    int n = nums.size();
    int res = 0;
    sort(nums.begin(), nums.end());
    vector<int> sum = {nums[0]};
    for (int i = 1; i < n; ++i) {
        int val = nums[i];
        if (val == nums[i - 1]) {
            sum.back() += val;
        } else if (val == nums[i - 1] + 1) {
            sum.push_back(val);
        } else {
            res += rob(sum);
            sum = {val};
        }
    }
    res += rob(sum);
    return res;
}

int rob(vector<int>& nums) {
    int size = nums.size();
    if (size == 1) return nums[0];
    int dp_1 = nums[0], dp_2 = max(nums[0], nums[1]);
    for (int i = 2; i < size; ++i) {
        int temp = dp_2;
        dp_2 = max(dp_2, dp_1 + nums[i]);
        dp_1 = temp;
    }
    return dp_2;
}