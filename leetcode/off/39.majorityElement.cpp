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

// review 2021年7月9日09:19:12
// 面试题17.10 主要元素有可能不存在
int majorityElement(vector<int>& nums) {
    int count = 0, major = -1;
    for (auto num : nums) {
        if (count == 0) {
            major = num;
        }
        
        if (num == major) ++count;
        else --count;
    }

    int check_cnt = 0;
    for (auto num : nums) {
        if (num == major) ++check_cnt;
    }

    return check_cnt > nums.size() / 2 ? major : -1;
}