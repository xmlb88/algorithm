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

        // 1 3 1 1 1   1 0 1 1 1   1 1 1 0 1 µÈÇé¿ö
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