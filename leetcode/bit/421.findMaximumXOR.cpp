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

// ÅÅÐò + ¼ôÖ¦
// https://leetcode-cn.com/problems/maximum-xor-of-two-numbers-in-an-array/solution/c-pai-xu-jia-jian-zhi-jian-dan-shi-xian-qj8su/

int findMaximumXOR(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    long long maxValue = 0;
    for (int i = n - 1; i >= 0; --i) {
        for (int j = i - 1; j >= 0; --j) {
            if ((long long)nums[i] + nums[j] < maxValue) break;
            maxValue = max(maxValue, (long long)nums[i] ^ nums[j]);
        }
    }
    return maxValue;
}

// Trie
