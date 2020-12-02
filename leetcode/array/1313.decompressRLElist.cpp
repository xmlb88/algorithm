#include <iostream>
#include <vector>
using namespace std;

vector<int> decompressRLElist(vector<int>& nums) {
    int n = nums.size();
    vector<int> res;
    for (int i = 0; i < n - 1; i += 2) {
        int j = i + 1;
        if (nums[i] == 0) continue;
        for (int k = 0; k < nums[i]; k++) res.push_back(nums[j]);
    }
    return res;
}