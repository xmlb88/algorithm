#include <iostream>
#include <vector>
using namespace std;

// µÝ¹é
vector<vector<int>> subsets(vector<int>& nums) {
    if (nums.size() == 0) return {{}};
    int n = nums.back();
    nums.pop_back();

    vector<vector<int>> res = subsets(nums);
    int size = res.size();
    for (int i = 0; i < size; i++) {
        vector<int> tmp = res[i];
        tmp.push_back(n);
        res.push_back(tmp);
    }

    return res;
}


// »ØËÝ
vector<vector<int>> res;
vector<vector<int>> subsets(vector<int>& nums) {
    vector<int> track;
    backtrace(nums, 0, track);
    return res;
}

void backtrace(vector<int>& nums, int start, vector<int>& track) {
    res.push_back(track);

    for (int i = start; i < nums.size(); i++) {
        track.push_back(nums[i]);
        backtrace(nums, i + 1, track);
        track.pop_back();
    }
}