#include <iostream>
#include <vector>
using namespace std;

int splitArray(vector<int>& nums, int m) {
    // 前缀和求和
    // int n = nums.size();
    // vector<int> pre(n);
    // pre[0] = nums[0];
    // for (int i = 1; i < n; i++) {
    //     pre[i] = pre[i - 1] + nums[i];
    // }
    
    // int lo = getMax(nums), hi = getSum(nums);
    // for (int max = lo; max <= hi; max++) {
    //     int n = split(nums, max);
    //     if (n <= m) {
    //         return max;
    //     }
    // }

    int lo = getMax(nums), hi = getSum(nums) + 1;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        int n = split(nums, mid);
        if (n == m) {
            hi = mid;
        } else if (n < m) {
            hi = mid;
        } else if (n > m) {
            lo = mid + 1;
        }
    }
    
    return lo;
}

int split(vector<int>& nums, int max) {
    int count = 1;
    int sum = 0;

    for (int i = 0; i < nums.size(); i++) {
        if (sum + nums[i] > max) {
            count++;
            sum = nums[i];
        } else {
            sum += nums[i];
        }
    }
    return count;
}

int getMax(vector<int>& nums) {
    int res = 0;
    for (int n : nums) {
        res = max(n, res);
    }
    return res;
}

int getSum(vector<int>& nums) {
    int res = 0;
    for (int n : nums) {
        res += n;
    }
    return res;
}

// review
int splitArray(vector<int>& nums, int m) {
    int lo = getMax(nums), hi = getSum(nums);
    
    //
    // for (int max = lo; max <= hi; max++) {
    //     int n = split(nums, max);
    //     if (n <= m) {
    //         return max;
    //     }
    // }
    // 二分优化

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        int n = split(nums, mid);
        if (n <= m) {
            hi = mid - 1;
        } else if (n > m) {
            lo = mid + 1;
        }
    }
    return lo;
}

int split(vector<int>& nums, int max) {
    int count = 1;
    int sum = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        if (sum + nums[i] > max) {
            sum = nums[i];
            count++;
        } else sum += nums[i];
    }
    return count;
}

int getMax(vector<int>& nums) {
    int res = nums[0];
    int n = nums.size();
    for (int i = 1; i < n; i++) {
        res = max(res, nums[i]);
    }
    return res;
}

int getSum(vector<int>& nums) {
    int res = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        res += nums[i];
    }
    return res;
}