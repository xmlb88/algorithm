#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// ����
bool find132pattern(vector<int>& nums) {
    if (nums.size() < 3) return false;
    for (int i = 0; i < nums.size() - 2; ++i) {
        for (int j = i + 1; j < nums.size() - 1; ++j) {
            for (int k = j + 1; k < nums.size(); ++k) {
                if (nums[i] < nums[k] && nums[k] < nums[j]) {
                    return true;
                }
            }
        }
    }
    return false;
}

// ����������3������1��Сֵ����������2
bool find132pattern(vector<int>& nums) {
    int n = nums.size();
    if (n < 3) return false;
    int left_min = nums[0];
    for (int i = 1; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (nums[j] > left_min && nums[i] > nums[j]) {
                return true;
            }
        }

        left_min = min(left_min, nums[i]);
    }
    return false;
}

// TODO: