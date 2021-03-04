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

// review
vector<int> findDisappearedNumbers(vector<int>& nums) {
    vector<int> res;

    for (int i = 0; i < nums.size(); i++) {
        nums[abs(nums[i]) - 1] = -1 * abs(nums[abs(nums[i]) - 1]);
    }

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] > 0) res.push_back(i + 1);
    }

    return res;
}


// review 2021年3月4日
// 改成负数
vector<int> findDisappearedNumbers(vector<int>& nums) {
    vector<int> res;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        if (nums[abs(nums[i]) - 1] < 0) continue;
        nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1];
    }

    for (int i = 0; i < n; i++) {
        if (nums[i] > 0) res.push_back(i + 1);
    }
    return res;
}

// +n
vector<int> findDisappearedNumbers(vector<int>& nums) {
    vector<int> res;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        nums[(nums[i] - 1) % n] += n;
    }

    for (int i = 0; i < n; i++) {
        if (nums[i] <= n) res.push_back(i + 1);
    }
    return res;
}