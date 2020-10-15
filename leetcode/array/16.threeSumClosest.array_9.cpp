#include <iostream>
#include <vector>
using namespace std;


// O(n^3)
int threeSumClosest(vector<int>& nums, int target) {
    int result = INT_MAX;
    int sum = 0;
    for (int i = 0; i < nums.size() - 2; i++) {
        for (int j = i + 1; j < nums.size() - 1; j++) {
            for (int k = j + 1; k < nums.size(); k++) {
               if (abs(nums[i] + nums[j] + nums[k] - target) < result) {
                    result = abs(nums[i] + nums[j] + nums[k] - target);
                    sum = nums[i] + nums[j] + nums[k];
               }
            }
        }
    }
    return sum;
}

// ÅÅÐò + Ë«Ö¸Õë
int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int res = INT_MAX;
    int result;
    for (int i = 0; i < n; i++) {
        int lo = i + 1, hi = n - 1;
        while (lo < hi) {
            int left = nums[lo], right = nums[hi];
            int sum = nums[i] + left + right;
            if (res > abs(sum - target)) {
                res = abs(sum - target);
                result = sum;
            }
            if (sum > target) {
                hi--;
            } else if (sum < target) {
                lo++;
            } else if (sum == target) {
                return target;
            }
        }
    }
    return result;
}