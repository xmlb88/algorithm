#include<iostream>
#include<vector>
using namespace std;

int missingNumber(vector<int>& nums) {
    int n = nums.size();
    int sum = 0;
    for (int num : nums) {
        sum += num;
    }

    return (n + 1) * (n / 2.0) - sum;
}

// 处理溢出
int missingNumber(vector<int>& nums) {
    int num = 0;
    for (int i = 0; i < nums.size(); i++) {
        num += i - nums[i];
    }

    return num + nums.size();
}

int missingNumber(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != i) return i;
    }
}

// 位运算，异或^
int missingNumber(vector<int>& nums) {
    int res = 0;
    for (int i = 0; i < nums.size(); i++) {
        res ^= i ^ nums[i];
    }

    res ^= nums.size();

    return res;
}