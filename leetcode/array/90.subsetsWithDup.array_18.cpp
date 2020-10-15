#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> res;
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<int> track;
    traceback(nums, 0, track);
    return res;
}

void traceback(vector<int>& nums, int start, vector<int>& track) {
    res.push_back(track);

    for (int i = start; i < nums.size(); i++) {
        if (i >= 1 && nums[i] == nums[i - 1]) continue;
        track.push_back(nums[i]);
        traceback(nums, i + 1, track);
        track.pop_back();
    }
}