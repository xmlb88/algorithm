#include <iostream>
#include <vector>
using namespace std;

// 暴力 超时
int countRangeSum(vector<int>& nums, int lower, int upper) {
    int count = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            long long sum = 0;
            for (int k = i; k <= j; k++) {
                sum += nums[k];
            }
            if (sum >= lower && sum <= upper) count++;
        }
    }
    return count;
}

// 前缀和 还是超时
int countRangeSum(vector<int>& nums, int lower, int upper) {
    int count = 0;
    int n = nums.size();
    vector<long long> pre(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + nums[i - 1];
    }

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            long long sum = pre[j + 1] - pre[i];
            if (sum >= lower && sum <= upper) count++;
        }
    }
    return count;
}

// nums = [1, 2, 3, 4, 5]
// pre = [0, 1, 3, 6, 10, 15]
// sum[2, 3] = 3 + 4 = 10 - 3 = pre[4] - pre[2]


// TODO:
// https://leetcode-cn.com/problems/count-of-range-sum/solution/multisetgui-bing-pai-xu-tong-su-jiang-jie-by-lzh_y/