#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <unordered_map>
using namespace std;

int minSubarray(vector<int>& nums, int p) {
    int n = nums.size();
    int sum = accumulate(nums.begin(), nums.end(), 0);
    int target = sum % p;
    if (target == 0) return 0;

    vector<int> preSum(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        preSum[i + 1] = preSum[i] + nums[i];
    }

    int min_length = INT_MAX;
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            int subSum = preSum[j + 1] - preSum[i];
            if ((subSum % p + p) % p == target) {
                min_length = min(min_length, j - i + 1);
            }
        }
    }
    return min_length == n ? -1 : min_length;
}

// https://leetcode-cn.com/problems/make-sum-divisible-by-p/solution/1590-shi-shu-zu-he-neng-bei-p-zheng-chu-zdxp2/

int minSubarray(vector<int>& nums, int p) {
    int n = nums.size(), mod = 0;
    for (auto& num : nums) {
        mod = (mod + num) % p;
    }
    if (mod == 0) return 0;

    int res = n, subMod = 0;
    unordered_map<int, int> mp;
    mp[0] = -1;
    for (int i = 0; i < n; ++i) {
        subMod = (subMod + nums[i]) % p;
        int target = (subMod - mod + p) % p;
        if (mp.find(target) != mp.end()) {
            res = min(res, i - mp[target]);
            if (res == 1 && res != n) {
                return res;
            }
        }
        mp[subMod] = i;
    }
    return res == n ? -1 : res;
}

// review own

int minSubarray(vector<int>& nums, int p) {
    int n = nums.size(), mod = 0;
    for (int i = 0; i < nums.size(); ++i) {
        mod = (mod + nums[i]) % p;
    }
    if (mod == 0) return 0;

    unordered_map<int, int> mp;
    mp[0] = -1;
    int subMod = 0, min_length = n;
    for (int i = 0; i < n; ++i) {
        subMod = (subMod + nums[i]) % p;
        int target = (subMod - mod + p) % p;
        if (mp.find(target) != mp.end()) {
            min_length = min(min_length, i - mp[target]);
            if (min_length == 1 && min_length != n) {
                return min_length;
            }
        }
        mp[subMod] = i;
    }
    return min_length == n ? -1 : min_length;
}