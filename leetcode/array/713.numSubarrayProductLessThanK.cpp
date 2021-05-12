#include <iostream>
#include <vector>
using namespace std;

int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    if (k <= 1) return 0;
    int multi = 1, res = 0, left = 0;
    for (int right = 0; right < nums.size(); ++right) {
        multi *= nums[right];
        while (multi >= k) {
            multi /= nums[left++];
        }
        res += right - left + 1;
    }
    return res;
}