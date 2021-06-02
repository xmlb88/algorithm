#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// WA [0, 0] 0
bool checkSubarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    if (n < 2) return false;
    vector<int> preSum(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        preSum[i + 1] = preSum[i] + nums[i];
    }

    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (preSum[j + 1] - preSum[i] == k || (k != 0 && (preSum[j + 1] - preSum[i]) % k == 0)) return true;
        }
    }
    return false;
}

// https://leetcode-cn.com/problems/continuous-subarray-sum/solution/lian-xu-de-zi-shu-zu-he-by-leetcode/
// 

bool checkSubarraySum(vector<int>& nums, int k) {
    int sum = 0;
    unordered_map<int, int> mp;
    mp[0] = -1;
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
        sum += nums[i];
        if (k != 0) {
            sum = sum % k;
        }

        if (mp.find(sum) != mp.end()) {
            if (i - mp[sum] > 1) return true;
        } else {
            mp[sum] = i;
        }
    }
    return false;
}


// Ç°×ººÍ + hash
bool checkSubarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    if (n <= 1) return false;

    int pre = 0;
    unordered_map<int, int> m;
    m[0] = -1;

    for (int i = 0; i < n; ++i) {
        pre += nums[i];
        int mod = pre % k;
        if (m.find(mod) != m.end()) {
            if (i - m[mod] >= 2) return true;
        } else m[mod] = i;
    }
    return false;
}