#include <iostream>
#include <vector>
using namespace std;

// 1 2 3 4
// 0 1 3 6 10

int pivotIndex(vector<int>& nums) {
    int n = nums.size();
    vector<int> preSum(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        preSum[i] = preSum[i - 1] + nums[i - 1];
    }

    for (int i = 0; i < n; i++) {
        int leftSum = preSum[i] - preSum[0];
        int rightSum = preSum[n] - preSum[i + 1];
        if (leftSum == rightSum) return i;
    }
    return -1;
}
// 1 7 3 6 5 6
// 0 1 8 11 17 22 28
// 
int pivotIndex(vector<int>& nums) {
    int total = accumulate(nums.begin(), nums.end(), 0);
    int sum = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (sum * 2 + nums[i] == total) {
            return i;
        }
        sum += nums[i];
    }
    return -1;
}