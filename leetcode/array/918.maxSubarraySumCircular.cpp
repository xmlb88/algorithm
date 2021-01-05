#include <iostream>
#include <vector>
using namespace std;

int maxSubarraySumCircular(vector<int>& nums) {
    if (nums.size() == 0) return 0;
    if (nums.size() == 1) return nums[0];

    int maxSubNum = maxSubArray(nums);
    int minSubNum = minSubArray(nums);

    int sum = 0;
    for(int v : nums) {
        sum += v;
    }

    return max(maxSubNum, sum - minSubNum);
}

// 普通非环形中的最大值
int maxSubArray(vector<int>& nums) {
    int n = nums.size();
    int maxnum = nums[0], res = nums[0];
    for (int i = 1; i < n; i++) {
        maxnum = max(maxnum + nums[i], nums[i]);
        res = max(res, maxnum);
    }
    return res;
}

// 普通非环形中的最小子数组值
// 不包括头和尾
int minSubArray(vector<int>& nums) {
    int n = nums.size();
    int minnum = nums[1], res = nums[1];
    for(int i = 2; i < n - 1; i++) {
        minnum = min(minnum + nums[i], nums[i]);
        res = min(res, minnum);
    }
    return res;
}