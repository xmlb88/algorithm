#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    // 先排序
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        vector<vector<int>> tuples = threeSum(nums, i + 1, target - nums[i]);
        for (auto tuple : tuples) {
            tuple.push_back(nums[i]);
            res.push_back(tuple);
        }
        // 去除重复数字
        while (i < n - 1 && nums[i] == nums[i + 1]) i++;
    }
    return res;
}

vector<vector<int>> threeSum(vector<int>& nums, int start, int target) {
    vector<vector<int>> res;
    int n = nums.size();
    for (int i = start; i < nums.size(); i++) {
        vector<vector<int>> tuples = twoSum(nums, i + 1, target - nums[i]);
        for (auto tuple : tuples) {
            tuple.push_back(nums[i]);
            res.push_back(tuple);
        }
        // 去除重复数字
        while (i < n - 1 && nums[i] == nums[i + 1]) i++;
    }
    return res;
}

vector<vector<int>> twoSum(vector<int>& nums, int start, int target) {
    vector<vector<int>> res;
    int n = nums.size();
    int i = start, j = n - 1;
    while (i < j) {
        int left = nums[i], right = nums[j];
        int sum = left + right;
        if (sum < target) {
            while (i < j && nums[i] == left) i++;
        } else if (sum > target) {
            while (i < j && nums[j] == right) j--;
        } else if (sum == target) {
            res.push_back({left, right});
            while (i < j && nums[i] == left) i++;
            while (i < j && nums[j] == right) j--;
        }
    }
    return res;
}