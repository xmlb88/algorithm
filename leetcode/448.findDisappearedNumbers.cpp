#include<iostream>
#include<vector>
using namespace std;


vector<int> findDisappearedNumbers(vector<int>& nums) {
    vector<bool> res(nums.size() + 1, false);
    vector<int> result;

    for (int num : nums) {
        res[num] = true;
    }

    for (int i = 1; i <= nums.size(); i++) {
        if (res[i] == false) result.push_back(i);
    }

    return result;
}

vector<int> findDisappearedNumbers(vector<int>& nums) {
    vector<int> result;

    for (int i = 0; i < nums.size(); i++) {
        nums[abs(nums[i]) - 1] = -1 * abs(nums[abs(nums[i]) - 1]);
    }

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] > 0) result.push_back(i + 1);
    }

    return result;
}