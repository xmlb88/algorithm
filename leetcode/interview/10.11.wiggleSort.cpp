#include <iostream>
#include <vector>
using namespace std;

// Ò»°ã·½·¨
void wiggleSort(vector<int>& nums) {
    if (nums.empty()) return;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 1; i += 2) {
        swap(nums[i], nums[i + 1]);
    }
}

// 2 3 1
void wiggleSort(vector<int>& nums) {
    if (nums.empty()) return;
    for (int i = 1; i < nums.size(); i++) {
        if (i & 1) {
            if (nums[i] > nums[i - 1]) swap(nums[i], nums[i - 1]);
        } else {
            if (nums[i] < nums[i - 1]) swap(nums[i], nums[i - 1]);
        }
    }
}