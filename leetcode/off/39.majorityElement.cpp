#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// 哈希
int majorityElement(vector<int>& nums) {
    unordered_map<int, int> count;
    for (int i = 0; i < nums.size(); i++) {
        count[nums[i]]++;
        if (count[nums[i]] > nums.size() / 2) return nums[i];
    }
    return -1;
}

// 排序 众数下标为n / 2
int majorityElement(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    return nums[nums.size() / 2];
}

// moore
int majorityElement(vector<int>& nums) {
    int majority = -1;
    int count = 0;
    for (int num : nums) {
        if (count == 0) {
            majority = num;
        }
        if (num == majority) count++;
        else count--;
    }
    return majority;
}