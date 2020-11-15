#include <iostream>
#include <vector>
#include <deque>
using namespace std;

// TODO: 
// 暴力 超时
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    if (k == 1 || nums.empty()) return nums;
    vector<int> res;
    for (int i = 0; i <= nums.size() - k; i++) {
        int maxNum = nums[i];
        for (int j = i + 1; j < i + k; j++) {
            maxNum = max(maxNum, nums[j]);
        }
        res.push_back(maxNum);
    }
    return res;
}

// 单调队列
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> window;
    vector<int> res;
    int i = 0;
    for (; i < k; i++) {
        while (!window.empty() && window.back() < nums[i]) {
            window.pop_back();
        }
        window.push_back(nums[i]);
    }
    res.push_back(window.front());

    for (; i < nums.size(); i++) {
        while (!window.empty() && window.back() < nums[i]) {
            window.pop_back();
        }
        window.push_back(nums[i]);
        res.push_back(window.front());
        if (window.front() == nums[i - k]) {
            window.pop_front();
        }
    }

    return res;
}

// 
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> window;
    vector<int> res;
    for (int i = 0; i < nums.size(); i++) {
        while (!window.empty() && window.back() < nums[i]) window.pop_back();
        window.push_back(nums[i]);
        if (i < k - 1) continue;
        else {
            res.push_back(window.front());
            if (!window.empty() && window.front() == nums[i - k + 1]) {
                window.pop_front();
            }
        }
    }
    return res;
}