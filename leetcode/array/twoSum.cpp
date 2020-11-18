#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// ¹þÏ£±í
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); i++) {
        if (map.find(target - nums[i]) != map.end()) {
            return {i, map[target - nums[i]]};
        } else {
            map[nums[i]] = i;
        }
    }

    return {-1, -1};
}

// ÅÅÐò + Ë«Ö¸Õë]
vector<int> twoSum(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int left = 0, right = nums.size() - 1;
    while (left < right) 
}