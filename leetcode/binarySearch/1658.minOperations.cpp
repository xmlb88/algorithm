#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;


bool canSub(vector<int>& nums, int x, int length) {
    int n = nums.size(), sum = 0;
    for (int i = 0; i < length; ++i) {
        sum += nums[i];
    }

    if (sum == x) return true;
    int left = length - 1, right = n - 1;
    while (left >= 0) {
        sum += nums[right] - nums[left];
        if (sum == x) return true;
        --left;
        --right;
    }
    return false;
}

// TLE
int minOperations(vector<int>& nums, int x) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum < x) return -1;
    for (int i = 1; i <= nums.size(); ++i) {
        if (canSub(nums, x, i)) {
            return i;
        }
    }
    return -1;
}

// WA
int minOperations(vector<int>& nums, int x) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum < x) return -1;
    int left = 0, right = nums.size() + 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (canSub(nums, x, mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    if (left == nums.size() + 1) return -1;
    return left;
}

int main() {
    vector<int> nums = {2,3,1,1,1};
    cout << minOperations(nums, 5) << endl;
}


// 双指针 求sum(nums) - x的最长连续子数组的长度
// https://leetcode-cn.com/problems/minimum-operations-to-reduce-x-to-zero/solution/c-san-chong-jie-fa-shuang-zhi-zhen-qian-drl5s/
//

int minOperations(vector<int>& nums, int x) {
    int n = nums.size(), ans = INT_MAX;
    int target = accumulate(nums.begin(), nums.end(), 0) - x;
    if (target == 0) return n;
    if (target < 0) return -1;
    int left = 0, right = 0, s = 0;
    while (right < n) {
        s += nums[right];
        ++right;
        while (s > target && left < right) {
            s -= nums[left];
            ++left;
        }
        if (s == target) ans = min(ans, n - (right - left));
    }
    if (ans == INT_MAX) return -1;
    return ans;
}

// 前缀和 + 二分查找
// https://leetcode-cn.com/problems/minimum-operations-to-reduce-x-to-zero/solution/c-san-chong-jie-fa-shuang-zhi-zhen-qian-drl5s/
// 

// 前缀和严格单调递增，枚举一个端点，二分查找另一个端点

// TODO:
int minOperations(vector<int>& nums, int x) {
    int n = nums.size(), ans = INT_MAX;
    vector<int> preSum(n + 1, 0);
    for (int i = 0; i < nums.size(); ++i) {
        preSum[i + 1] = preSum[i] + nums[i];
    }

    if (preSum[n] < x) return -1;

    for (int right = 0; right <= n; ++right) {
        int target = x - (preSum[n] - preSum[right]);
        int left = lower_bound(preSum.begin(), preSum.end(), target) - preSum.begin();
        if (left <= n && preSum[left] == target) ans = min(ans, left);
    }
    if (ans = INT_MAX) return -1;
    return ans;
}