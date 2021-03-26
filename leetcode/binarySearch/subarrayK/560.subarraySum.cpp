#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// violence
int subarraySum(vector<int>& nums, int k) {
    int count = 0;
    for (int start = 0; start < nums.size(); ++start) {
        int sum = 0;
        for (int end = start; end >= 0; --end) {
            sum += nums[end];
            if (sum == k) {
                ++count;
            }
        }
    }
    return count;
}

// https://leetcode-cn.com/problems/subarray-sum-equals-k/solution/he-wei-kde-zi-shu-zu-by-leetcode-solution/
//
int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> mp;
    mp[0] = 1;
    int count = 0, pre = 0;
    for (auto& x : nums) {
        pre += x;
        if (mp.find(pre - k) != mp.end()) {
            count += mp[pre - k];
        }
        mp[pre]++;
    }
    return count;
}

// 前缀和
int subarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> preSum(n + 1);
    preSum[0] = 0;

    for (int i = 0; i < n; ++i) {
        preSum[i + 1] = preSum[i] + nums[i];
    }

    int count = 0;
    for (int left = 0; left < n; ++left) {
        for (int right = left; right < n; ++right) {
            if (preSum[right + 1] - preSum[left] == k) {
                count++;
            }
        }
    }
    return count;
}

// 前缀和 + 哈希表
int subarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    unordered_map<int, int> mp;
    int pre = 0, count = 0;
    mp[0] = 1;
    for (int i = 0; i < n; ++i) {
        pre += nums[i];
        if (mp.find(pre - k) != mp.end()) {
            count += mp[pre - k];
        }
        mp[pre]++;
    }
    return count;
}