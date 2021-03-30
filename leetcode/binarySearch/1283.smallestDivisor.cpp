#include <iostream>
#include <vector>
using namespace std;

// 二分 own
bool check(vector<int>& nums, int threshold, int divisor) {
    int sum = 0;
    for (int num : nums) {
        sum += num % divisor == 0 ? num / divisor : num / divisor + 1;
    }
    return sum <= threshold;
}

int smallestDivisor(vector<int>& nums, int threshold) {
    int left = 1, right = *max_element(nums.begin(), nums.end()) + 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (check(nums, threshold, mid)) {
            right = mid;
        } else left = mid + 1;
    }
    return right;
}

// https://leetcode-cn.com/problems/find-the-smallest-divisor-given-a-threshold/solution/shi-jie-guo-bu-chao-guo-yu-zhi-de-zui-xiao-chu-s-3/
// 

int smallestDivisor(vector<int>& nums, int threshold) {
    int l = 1, r = *max_element(nums.begin(), nums.end());
    int ans = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        int total = 0;
        for (int num : nums) {
            total += (num - 1) / mid + 1; // 向上取整
        }

        if (total <= threshold) {
            ans = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    return ans;
}