#include <iostream>
#include <vector>
using namespace std;

// ^
int missingNumber(vector<int>& nums) {
    int n = nums.size();
    int res = 0;
    for (int i = 0; i < n; i++) {
        res ^= nums[i];
        res ^= i + 1;
    }
    return res;
}

// ¶þ·Ö²éÕÒ
int missingNumber(vector<int>& nums) {
    int n = nums.size();
    int left = 0, right = n;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == mid) {
            left = mid + 1;
        } else if (nums[mid] == mid + 1) {
            right = mid;
        }
    }
    return left;
}