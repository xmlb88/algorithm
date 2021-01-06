#include <iostream>
#include <vector>
using namespace std;

int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
    int n = matrix.size();
    if (n == 0) return 0;
    int m = matrix[0].size();
    int maxSum = INT_MIN;

    for(int i = 0; i < n; i++) {
        vector<int> b(m, 0);
        for (int j = i; j < n; j++) {
            for (int k = 0; k < m; k++) {
                b[k] += matrix[j][k];
            }

            maxSum = max(maxSum, maxSumLessK(b, k));
            if (maxSum == k) return k;
        }
    }
    return maxSum;
}

// 暴力求nums数组中小于等于k的最大子数组和
int maxSumLessK(vector<int>& nums, int k) {
    int n = nums.size();
    int maxSum = INT_MIN;
    int dp = 0;
    for (int i = 0; i < n; i++) {
        if (dp > 0) {
            dp += nums[i];
        } else {
            dp = nums[i];
        }

        maxSum = max(maxSum, dp);
    }

    if (maxSum <= k) return maxSum;
    maxSum = INT_MIN;

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += nums[j];
            if (sum == k) return k;
            if (sum > maxSum && sum < k) {
                maxSum = sum;
            }
        }
    }
    return maxSum;
}