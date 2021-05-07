#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dominantIndex(vector<int>& nums) {
    int index = max_element(nums.begin(), nums.end()) - nums.begin();
    for (int i = 0; i < nums.size(); ++i) {
        if (i == index) continue;

        if (nums[index] < nums[i] * 2) return -1;
    }
    return index;
}