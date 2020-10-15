#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    for (int i = 0; i < nums.size() - 2; i++) {
        for (int j = i + 1; j < nums.size() - 1; j++) {
            for (int k = j + 1; k < nums.size(); k++) {
                if (nums[i] + nums[j] + nums[k] == 0) {
                    result.push_back({nums[i], nums[j], nums[k]});
                }
            }
        }
    }
    return result;
}



// 
vector<vector<int>> twoSumTarget(vector<int>& nums, int start, int target) {
    // 左指针从start开始
    int i = start, j = nums.size() - 1;
    vector<vector<int>> res;
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

vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<vector<int>> res;

    // 穷举第一个数
    for (int i = 0; i < n; i++) {
        // 对target - nums[i]计算twoSum
        vector<vector<int>> tuples = twoSumTarget(nums, i + 1, 0 - nums[i]);
        for (vector<int>& tuple : tuples) {
            tuple.push_back(nums[i]);
            res.push_back(tuple);
        }
        // 跳过重复数字
        while (i < n - 1 && nums[i] == nums[i + 1]) i++;
    }
    return res;
}

vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<vector<int>> res;
    for (int i = 0; i < n; i++) {
        int lo = i + 1, hi = n - 1;
        int target = - nums[i];
        while (lo < hi) {
            int left = nums[lo], right = nums[hi];
            int sum = left + right;
            if (sum < target) {
                while (lo < hi && nums[lo] == left) lo++;
            } else if (sum > target) {
                while (lo < hi && nums[hi] == right) hi--;
            } else if (sum == target) {
                res.push_back({nums[i], left, right});
                while (lo < hi && nums[lo] == left) lo++;
                while (lo < hi && nums[hi] == right) hi--;
            }
        }
        while (i < n - 1 && nums[i] == nums[i + 1]) i++;
    }
    return res;
}