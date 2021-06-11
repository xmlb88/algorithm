#include <iostream>
#include <vector>
using namespace std;

bool check(vector<int>& nums, int k, int diff) {
    int count = 0;
    int n = nums.size(), r = 0;
    for (int l = 0; l < nums.size(); ++l) {
        while (r < n && nums[r] - nums[l] <= diff)
            ++r;
        count += r - l - 1;
    }
    return count >= k;
}

int smallestDistancePair(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int n = nums.size(), left = 0, right = nums[n - 1] - nums[0];
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (check(nums, k, mid)) {
            right = mid;
        } else left = mid + 1;
    }
    return left;
}