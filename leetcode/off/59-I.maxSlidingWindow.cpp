#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> window;
    vector<int> res;
    for (int i = 0; i < nums.size(); i++) {
        while (!window.empty() && window.back() < nums[i]) window.pop_back();
        window.push_back(nums[i]);
        if (i < k - 1) continue;
        else {
            res.push_back(window.front());
            if (!window.empty() && window.front() == nums[i - k + 1]) window.pop_front();
        }
    }
    return res;
}