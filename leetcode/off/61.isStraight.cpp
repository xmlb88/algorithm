#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool isStraight(vector<int>& nums) {
    int maximum = 0, minimum = 14;
    unordered_set<int> set;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 0) continue;
        if (set.count(nums[i])) return false;
        set.insert(nums[i]);
        maximum = max(maximum, nums[i]);
        minimum = min(minimum, nums[i]);
    }
    return maximum - minimum < 5;
}