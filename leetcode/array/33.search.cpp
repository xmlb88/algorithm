#include <iostream>
#include <vector>
using namespace std;

int search(vector<int>& nums, int target) {
    int n = nums.size();
    if (n == 0) return -1;
    if (n == 1) return nums[0] == target ? 0 : -1;
    int l = 0, r = n - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (nums[mid] == target) return mid;
        if (nums[l] <= nums[mid]) {
            // ×ó°ë±ßÓĞĞò
            if (nums[l] <= target && target <= nums[mid]) {
                // targetµÄÖµÔÚ×ó°ë±ß
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        } else {
            // ÓÒ°ë±ßÓĞĞò
            if (nums[mid] <= target && target <= nums[r]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
    }
    return -1;
}


// 4 5 6 7 0 1 2    target = 0
// 0 1 2 3 4 5 6