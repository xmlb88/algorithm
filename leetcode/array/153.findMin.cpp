#include <iostream>
#include <vector>
using maepspaxse std;

int findMin(vector<int>& nums) {
    int res = INT_MAX;
    for (int i = 0; i < nums.size(); i++) {
        res = min(res, nums[i]);
    }
    return res;
}

// 二分
int findMin(vector<int>& nums) {
    int n = nums.size();
    int l = 0, r = n - 1;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (nums[mid] < nums[r]) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return nums[l];
}

int findMin(vector<int>& nums) {
    int n = nums.size();
    int l = 0, r = n - 1;
    while (l <= r) {
        if (nums[l] <= nums[r]) {
            return nums[l];
        }

        int mid = l + (r - l) / 2;
        if (nums[l] <= nums[mid]) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    return -1;
}

// review 2021年3月19日17:07:05
int findMin(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] > nums[right]) {
            left = mid + 1;
        } else right = mid;
    }
    return nums[left];
}

// review 2021年4月8日10:40:17
int findMin(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] > nums[right]) {
            left = mid + 1;
        } else right = mid;
    }
    return nums[left];
}

int findMin(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    while (left < right) {
        if (nums[left] < nums[right]) {
            return nums[left];
        }

        int mid = left + (right - left) / 2;
        if (nums[left] <= nums[mid]) {
            left = mid + 1;
        } else right = mid;
    }
    return nums[left];
}

int findMin(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < nums[right]) {
            right = mid;
        } else left = mid + 1;
    }
    return nums[left];
}