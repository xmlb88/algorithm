#include <iostream>
#include <vector>
using namespace std;

int findMaximumXOR(vector<int>& nums) {
    int n = nums.size(), maxXor = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            maxXor = max(maxXor, nums[i] ^ nums[j]);
        }
    }
    return maxXor;
}

// TODO:

