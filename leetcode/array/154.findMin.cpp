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