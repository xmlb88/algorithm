#include<iostream>
#include<vector>
using namespace std;

vector<int> findDuplicates(vector<int>& nums) {
    int n = nums.size();
    vector<int> result;
    for (int i = 0; i < n; i++) {
        if (nums[abs(nums[i]) - 1] < 0) {
            result.push_back(abs(nums[i]));
        } else {
            nums[abs(nums[i]) - 1] *= -1;
        }
    }

    return result;
}

// review
vector<int> findDuplicates(vector<int>& nums) {
    vector<int> res;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[abs(nums[i]) - 1] < 0) {
            res.push_back(abs(nums[i]));
        } else {
            nums[abs(nums[i]) - 1] *= -1;
        }
    }
    return res;
}
