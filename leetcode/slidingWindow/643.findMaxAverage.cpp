#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

double findMaxAverage(vector<int>& nums, int k) {
    int n = nums.size();
    int left = 0, right = 0;
    double res;
    int sum = 0;
    int maxSum = INT_MIN;
    while (right < n) {
        sum += nums[right];
        right++;

        if (right - left == k) {
            maxSum = max(maxSum, sum);
            sum -= nums[left];
            left++;
        }
    }
    return static_cast<double>(maxSum) / k;
}

double findMaxAverage(vector<int>& nums, int k) {
    int n = nums.size();
    int sum = 0;

    for (int i = 0; i < k; i++) {
        sum += nums[i];
    }

    int maxSum = sum;
    for (int i = k; i < n; i++) {
        sum = sum + nums[i] - nums[i - k];
        maxSum = max(maxSum, sum);
    }

    return static_cast<double>(maxSum) / k;
}

// 1 2 3 4 5