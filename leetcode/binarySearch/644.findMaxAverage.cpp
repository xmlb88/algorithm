#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;


// nums = [1,12,-5,-6,50,3], k = 4
// 二分法
// TODO:
double findMaxAverage(vector<int>& nums, int k) {
    int n = nums.size();
    double l = INT_MAX;
    double r = 0;
    for (int i = 0; i < n; ++i) {
        if (nums[i] < l) {
            l = nums[i];
        }

        if (nums[i] > r) {
            r = nums[i];
        }
    }

    double mid = (l + r) * 0.5;
    double prevMid = 0.0;
    while (abs(prevMid - mid) > 1e-5) {
        if (Check(mid, nums, k)) {
            l = mid;
        } else {
            r = mid;
        }
        prevMid = mid;
        mid = (l + r) * 0.5;
    }

    return mid;
}

bool Check(double mid, const vector<int>& nums, int k) {
    // 当前累计的和
    double sumj = 0;
    // 前缀累计的和(k个元素前的)
    double sumi = 0;
    // 则计算前缀和就是sumj - sumi
    // 记录最小的sumi, 0个元素时候初始化为0
    double minSumi = 0;

    int n = nums.size();
    for (int i = 0; i < k; ++i) {
        sumj += nums[i] - mid;
    }

    // 第一组k个数组已满足，则返回true
    if (sumj >= 0) return true;

    for (int i = k; i < n; ++i) {
        sumj += nums[i] - mid;
        sumi += nums[i - k] - mid;
        minSumi = min(minSumi, sumi);
        if (sumj - minSumi >= 0) return true;
    }
    return false;
}