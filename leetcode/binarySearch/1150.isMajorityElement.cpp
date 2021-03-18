#include <iostream>
#include <vector>
using namespace std;

// 暴力
bool isMajorityElement(vector<int>& nums, int target) {
    int n = nums.size();
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] == target) count++;
    }
    return count > n / 2;
}

// 二分左右边界
int left_bound(vector<int>& nums, int target) {
    int left = 0, right = nums.size();
    while (left < right) {
        int mid = left + right >> 1;
        if (nums[mid] == target) {
            right = mid;
        } else if (nums[mid] > target) {
            right = mid;
        } else if (nums[mid] < target) {
            left = mid + 1;
        }
    }
    return left;
}

int right_bound(vector<int>& nums, int target) {
    int left = 0, right = nums.size();
    while (left < right) {
        int mid = left + right >> 1;
        if (nums[mid] == target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid;
        } else if (nums[mid] < target) {
            left = mid + 1;
        }
    }
    return left - 1;
}
// 1 2 2 2 2 3
// 0 5 2
// 0 1 0
// 1 1 1
// 1 0 

bool isMajorityElement(vector<int>& nums, int target) {
    int l = left_bound(nums, target), r = right_bound(nums, target);
    return (r - l + 1) > nums.size() / 2;
}