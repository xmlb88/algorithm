#include <iostream>
#include <vector>
using namespace std;

bool search(vector<int>& nums, int target) {
    int n = nums.size();
    if (n == 0) return false;
    if (n == 1) return nums[0] == target ? true : false;
    int l = 0, r = n - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (nums[mid] == target) return true;

        // 1 3 1 1 1   1 0 1 1 1   1 1 1 0 1 等情况
        if (nums[l] == nums[mid]) {
            l++;
            continue;
        }

        if (nums[l] < nums[mid]) {
            if (nums[l] <= target && target <= nums[mid]) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        } else {
            if (nums[mid] <= target && target <= nums[r]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
    }
    return false;
}

// review 2021?4?7?09:12:15
// 1 0 1 1 1
// WA 1 0 1 1 1
bool search(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) return true;
        // 解决1 0 1 1 1等情况，去掉重复项
        if (nums[left] == nums[mid]) {
            left++;
            continue;
        }
        if (nums[left] < nums[mid]) {
            if (nums[left] <= target && target <= nums[mid]) {
                right = mid - 1;
            } else left = mid + 1;
        } else {
            if (nums[mid] <= target && target <= nums[right]) {
                left = mid + 1;
            } else right = mid - 1;
        }
    }
    return false;
}