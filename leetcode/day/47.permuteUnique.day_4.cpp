#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> result;
vector<vector<int>> permuteUnique(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<int> record(nums.size(), 0);
    vector<int> vec;
    backtrace(nums, vec, record);
    return result;
}

void backtrace(vector<int>& nums, vector<int>& vec, vector<int>& record) {
    if (vec.size() == nums.size()) {
        result.push_back(vec);
        return;
    }

    for (int i = 0; i < nums.size(); i++) {
        if (record[i] || (i > 0 && nums[i] == nums[i - 1] && !record[i - 1])) continue;
        vec.push_back(nums[i]);
        record[i] = 1;
        backtrace(nums, vec, record);
        vec.pop_back();
        record[i] = 0;
    }
}