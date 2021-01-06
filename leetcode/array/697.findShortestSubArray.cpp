#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int findShortestSubArray(vector<int>& nums) {
    unordered_map<int, int> m;
    for (int n : nums) {
        m[n]++;
    }

    int degree = 0;
    int length = nums.size();
    for (auto it = m.begin(); it != m.end(); it++) {
        degree = max(degree, (*it).second);
        // if ((*it).second >= degree) {
        //     degree = (*it).second;
        //     length = min(length, subLength(nums, (*it).first));
        // }
    }

    for (auto it = m.begin(); it != m.end(); it++) {
        if ((*it).second == degree) {
            length = min(length, subLength(nums, (*it).first));
        }
    }
    return length;
}

int subLength(vector<int>& nums, int n) {
    int i = 0, j = nums.size() - 1;
    while (i < nums.size() && nums[i] != n) i++;
    while (j >= 0 && nums[j] != n) j--;

    return j - i + 1;
}