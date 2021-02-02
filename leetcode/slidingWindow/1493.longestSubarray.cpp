#include <iostream>
#include <vector>
using namespace std;

int longestSubarray(vector<int>& nums) {
    int n = nums.size();
    int left = 0, right = 0;
    int zeroNum = 0;
    while (right < n) {
        if (nums[right] == 0) zeroNum++;
        right++;

        if (zeroNum > 1) {
            if (nums[left] == 0) zeroNum--;
            left++;
        }
    }
    return right - left - 1;
}