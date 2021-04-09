#include <iostream>
#include <vector>
using namespace std;

int findMin(vector<int>& nums) {
    int n = nums.size();
    int l = 0, r = n - 1;

    while (l < r) {
        int mid = l + (r - l) / 2;
        if (nums[mid] > nums[r]) {
            l = mid + 1;
        } else if (nums[mid] < nums[r]) {
            r = mid;
        } else if (nums[mid] == nums[r]) {
            r--;
        }
    }
    return nums[l];
}

int findMin(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    while (left < right) {
        if (nums[left] < nums[right]) {
            return nums[left];
        }
        int mid = left + (right - left) / 2;
        if (nums[left] == nums[mid]) {
            ++left;
        } else if (nums[left] < nums[mid]) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return nums[left];
}

// nums[mid] Óë nums[left]
//
int findMin(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == nums[right]) --right;
        else if (nums[mid] < nums[right]) right = mid;
        else left = mid + 1;
    }
    return nums[left];
}