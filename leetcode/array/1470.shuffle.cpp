#include <iostream>
#include <vector>
using namespace std;

vector<int> shuffle(vector<int>& nums, int n) {
    vector<int> res;
    for (int i = 0, j = n; i < n && n < nums.size(); i++, j++) {
        res.push_back(nums[i]);
        res.push_back(nums[j]);
    }
    return res;
}