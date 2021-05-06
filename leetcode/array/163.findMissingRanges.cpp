#include <iostream>
#include <vector>
#include <string>
using namespace std;

string missingRange(int start, int end) {
    if (start == end) {
        return to_string(start);
    } else {
        return to_string(start) + "->" + to_string(end);
    }
}

vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
    if (nums.empty()) return {missingRange(lower, upper)};
    int n = nums.size();
    vector<string> res;
    if (lower < nums[0]) {
        res.push_back(missingRange(lower, nums[0] - 1));
    }

    for (int i = 0; i < n - 1; ++i) {
        if (nums[i] + 1 == nums[i + 1]) continue;

        if (nums[i] + 1 < nums[i + 1]) {
            res.push_back(missingRange(nums[i] + 1, nums[i + 1] - 1));
        }
    }

    if (nums.back() < upper) {
        res.push_back(missingRange(nums.back() + 1, upper));
    }
    return res;
}