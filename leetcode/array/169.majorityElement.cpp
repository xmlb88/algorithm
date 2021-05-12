#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// 哈希
int majorityElement(vector<int>& nums) {
    unordered_map<int, int> count;
    for (int i = 0; i < nums.size(); i++) {
        count[nums[i]]++;
        if (count[nums[i]] > nums.size() / 2) return nums[i];
    }
    return -1;
}

// 排序 众数下标为n / 2
int majorityElement(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    return nums[nums.size() / 2];
}

// moore
int majorityElement(vector<int>& nums) {
    int majority = -1;
    int count = 0;
    for (int num : nums) {
        if (count == 0) {
            majority = num;
        }
        if (num == majority) count++;
        else count--;
    }
    return majority;
}

// review 2021年5月7日10:36:27
// 暴力hash
int majorityElement(vector<int>& nums) {
    int n = nums.size();
    unordered_map<int, int> m;
    for (int num : nums) {
        m[num]++;
        if (m[num] > n / 2) return num;
    }
    return -1;
}

// 排序，众数下标n / 2
int majorityElement(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    return nums[nums.size() / 2];
}

// 随机化
int majorityElement(vector<int>& nums) {
    while(true) {
        int candidate = nums[rand() % nums.size()];
        int count = 0;
        for (int num : nums) {
            if (num == candidate) ++count;
        }
        if (count > nums.size() / 2) return candidate;
    }
    return -1;
}

// 分治法

// Moore投票法
int majorityElement(vector<int>& nums) {
    int count = 0, candidate;
    for (int num : nums) {
        if (count == 0) {
            candidate = num;
        }

        if (num == candidate) ++count;
        else --count;
    }
    return candidate;
}

// review 2021年5月12日10:52:42
// interview 17.10 不一定存在，需验证
int majorityElement(vector<int>& nums) {
    unordered_map<int, int> m;
    for (auto num : nums) {
        m[num]++;
    }

    for (auto& [num, count] : m) {
        if (count > nums.size() / 2) return num;
    }
    return -1;
}

// 排序
// int majorityElement(vector<int>& nums) {
//     sort(nums.begin(), nums.end());
//     return nums[nums.size() / 2];
// }

// Moore
int majorityElement(vector<int>& nums) {
    int count = 0, candidate;
    for (int num : nums) {
        if (count == 0) {
            candidate = num;
        }
        if (num == candidate) ++count;
        else --count;
    }

    count = 0;
    for (int num : nums) {
        if (num == candidate) ++count;
    }
    if (count > nums.size() / 2) return candidate;
    return -1;
}