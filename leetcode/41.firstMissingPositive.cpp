#include<iostream>
#include<vector>
using namespace std;

int firstMissingPositive(vector<int>& nums) {
    int target = 1;
    sort(nums.begin(), nums.end());
    for (int num : nums) {
        if (num <= 0) continue;
        else if (num == target) {
            target++;
        } else if (num < target) {
            continue;
        } else return target;
    }
    return target;
}

int firstMissingPositive(vector<int>& nums) {
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] <= 0) nums[i] = nums.size() + 1;
    }

    for (int i = 0; i < nums.size(); i++) {
        if (abs(nums[i]) == nums.size() + 1) {
            continue;
        } else {
            int tmp = abs(nums[i]) - 1;
            nums[tmp] = -abs(nums[tmp]);
        }
    }

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] > 0) {
            return i + 1;
        }
    }

    return nums.size() + 1;
}