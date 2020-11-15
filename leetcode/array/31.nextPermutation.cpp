#include <iostream>
#include <vector>
using namespace std;

void nextPermutation(vector<int>& nums) {
    next_permutation(nums.begin(), nums.end());
}

void nextPermutation(vector<int>& nums) {
    int n = nums.size();

    int i = n - 2;
    // 找到序列中a[i] < a[i + 1]的数，找不到i为-1
    while (i >= 0 && nums[i] >= nums[i + 1]) {
        i--;
    }

    if (i >= 0) {
        int j = n - 1;
        while (j >= 0 && nums[i] >= nums[j]) {
            j--;
        }
        swap(nums[i], nums[j]);
    }

    reverse(nums.begin() + i + 1, nums.end());

    return;
}

// 1 3 5 7 4 6 2