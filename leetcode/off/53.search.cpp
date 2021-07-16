#include <iostream>
#include <vector>
using namespace std;

int search(vector<int>& nums, int target) {
    int n = nums.size();
    int left = 0, right = n - 1;
    int left_bound = 0, right_bound = 0;
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

    // if (left >= n || nums[left] != target) return 0;
    left_bound = left;

    left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            left = mid + 1;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid - 1;
        }
    }

    if (right < 0 || nums[right] != target) return 0;
    right_bound = right;
    return right_bound - left_bound + 1;
}


int search(vector<int>& numss, int target) {
    return upper_bound(nums.begin(), nums.end(), target) - lower_bound(nums.begin(), nums.end(), target);
}


int search(vector<int>& nums, int target) {
    int n = nums.size();
    int left = 0, right = n;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] >= target) {
            right = mid;
        } else left = mid + 1;
    }
    int left_bound = left;
    left = 0, right = n;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] <= target) {
            left = mid + 1;
        } else right = mid;
    }

    int right_bound = left;
    return right_bound - left_bound;
}