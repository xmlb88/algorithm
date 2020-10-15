#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int subarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    // 构造前缀和
    vector<int> sum(n + 1, 0);
    for (int i = 0; i < n; i++) {
        sum[i + 1] = sum[i] + nums[i];
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            // sum of nums[j ... i - 1]
            if (sum[i] - sum[j] == k) ans++;
        }
    }
    return ans;
}

// 0 1 2 3  4 5
// 3 5 2 -2 4 1

// presum:
// 0 1 2 3  4 5  6
// 0 3 8 10 8 12 13

int subarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> presum(n + 1, 0);
    for (int i = 0; i < n; i++) {
        presum[i + 1] = presum[i] + nums[i];
    }

    unordered_map<int, int> map;
    map[0] = 1;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (map.count(presum[i] - k) > 0) ans += map[presum[i] - k];
        map[presum[i]] += 1;
    }

    return ans;
}

// 优化空间
int subarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    unordered_map<int, int> map;
    int presum = 0;
    int ans = 0;
    map[0] = 1;
    for (int i = 0; i < n; i++) {
        presum += nums[i];
        if (map.count(presum - k) > 0) ans += map[presum - k];
        map[presum] += 1;
    }
    return ans;
}