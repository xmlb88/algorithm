#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// 暴力
vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
    vector<int> res;
    for (int i = 0; i < nums.size(); i++) {
        int count = 0;
        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] < nums[i]) {
                count++;
            }
        }
        res.push_back(count);
    }
    return res;
}

// 计数排序
vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
    vector<int> count(101, 0);
    for (int i = 0; i < nums.size(); i++) {
        count[nums[i]]++;
    }

    for (int i = 1; i <= 100; i++) {
        count[i] += count[i - 1];
    }

    vector<int> res;
    for (int i = 0; i < nums.size(); i++) {
        res.push_back(nums[i] == 0? 0 : count[nums[i] - 1]);
    }
    return res;
}

// 快速排序 + 哈希
vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
    vector<int> vec = nums;
    sort(vec.begin(), vec.end());
    int hash[101];
    for (int i = vec.size() - 1; i >= 0; i--) {
        hash[vec[i]] = i;
    }
    vector<int> res;
    for (int i = 0; i < nums.size(); i++) {
        res.push_back(hash[nums[i]]);
    }
    return res;
}

