#include <iostream>
#include <vector>
using namespace std;

int minSubArrayLen(int s, vector<int>& nums) {
    int n = nums.size();
    int left = 0, right = 0;
    int sum = 0, length = INT_MAX;
    while (right < n) {
        sum += nums[right];
        right++;

        while (sum >= s) {
            length = min(length, right - left); // 在这里更新结果
            sum -= nums[left];
            left++;
        }
    }
    return length == INT_MAX ? 0 : length;
}