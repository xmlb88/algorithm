#include<iostream>
#include<vector>
using namespace std;

vector<int> findErrorNums(vector<int>& nums) {
    vector<int> res(nums.size(), 0);
    int miss, dup;
    for (int num : nums) {
        if (res[num - 1] == 1) dup = num;
        res[num - 1] += 1;
    }

    for (int i = 0; i < nums.size(); i++) {
        if (res[i] == 0) {
            miss = i + 1;
            break;
        }
    }

    return {dup, miss};
}

vector<int> findErrorNums(vector<int>& nums) {
    int dup, miss;
    for (int i = 0; i < nums.size(); i++) {
        int n = abs(nums[i]);
        if (nums[n - 1] < 0) {
            dup = n;
        } else {
            nums[n - 1] *= -1;
        }
    }

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] > 0) {
            miss = i + 1;
        }
    }
    
    return {dup, miss};
}