#include <iostream>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left < right) {
        if (nums[left] + nums[right] == target) return {nums[left], nums[right]};
        else if (nums[left] + nums[right] > target) right--;
        else if (nums[left] + nums[right] < target) left++;
    }
    return {-1, -1};
}