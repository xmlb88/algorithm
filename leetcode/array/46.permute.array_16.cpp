#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> res;
vector<vector<int>> permute(vector<int>& nums) {
    vector<int> track;
    backtrace(nums, track);
    return res;
}

void backtrace(vector<int>& nums, vector<int>& track) {
    if (track.size() == nums.size()) {
        res.push_back(track);
        return;
    }

    for (int i = 0; i < nums.size(); i++) {
        auto it = find(track.begin(), track.end(), nums[i]); // find查找vector中是否存在
        if (it != track.end()) continue;
        track.push_back(nums[i]);
        backtrace(nums, track);
        track.pop_back();
    }
}