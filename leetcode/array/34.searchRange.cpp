#include <iostream>
#include <vector>
using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
    int n = nums.size();
    int left = 0, right = n - 1;
    int left_bound, right_bound;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            right = mid - 1;
        } else if (nums[mid] > target) {
            right = mid - 1;
        } else if (nums[mid] < target) {
            left = mid + 1;
        }
    }

    if (left >= n || nums[left] != target) return {-1, -1};
    left_bound = left;

    left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid - 1;
        } else if (nums[mid] < target) {
            left = mid + 1;
        }
    }
    right_bound = right;

    return {left_bound, right_bound};
}

// 1 2 3 4 5 target = 6
// left = 0 right = 4 mid = 2 nums[mid] = 3 < 6 
// left = 3 right = 4 mid = 3 nums[mid] = 4 < 6
// left = 4 right = 4 mid = 4 nums[mid] = 5 < 6
// left = 5 right = 4

// 2 3 4 5 6 7 target = 1
// left = 0 right = 5 mid = 2 nums[mid] = 4 > 1
// left = 0 right = 1 mid = 0 nums[mid] = 2 > 1
// left = 0 right = -1

// 2 3 3 3 4 5 6 target = 3
// left = 0 right = 6 mid = 3 nums[mid] = 3 = 3 
// left = 0 right = 2 mid = 1 nums[mid] = 3 = 3 left = 4 right = 6 mid = 5 nums[mid] = 5 > 3
// left = 0 right = 0 mid = 0 nums[mid] = 2 < 3 left = 4 right = 4 mid = 4 nums[mid] = 4 > 3
// left = 1 right = 0                           left = 4 right = 3