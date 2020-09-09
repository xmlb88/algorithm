/*
 * @Author: your name
 * @Date: 2020-06-19 19:53:14
 * @LastEditTime: 2020-06-19 20:23:02
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \Algorithm\maxSubArray.cpp
 */ 

#include <iostream>
#include <vector>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    vector<int> dp(n);

    //base case
    //第一个元素前没有数组
    dp[0] = nums[0];
    for (int i = 1; i < n; i++) {
        dp[i] = max(nums[i], nums[i] + dp[i - 1]);
    }

    //得到nums的最大数组
    int res = INT_MIN;
    for (int i = 0; i < n; i++) {
        res = max(res, dp[i]);
    }

    return res;
}

int main() {
    vector<int> a = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << maxSubArray(a) << endl;
    return 0;
}