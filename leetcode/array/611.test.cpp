#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binarySearch(vector<int>& nums, int left, int right, int x) {
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] <= x) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

int triangleNumber(vector<int>& nums) {
    if (nums.size() < 3) return 0;
    sort(nums.begin(), nums.end());
    int res = 0;
    for (int i = 0; i < nums.size() - 2; ++i) {
        int k = i + 2;
        for (int j = i + 1; j < nums.size() - 1; ++j) {
            k = binarySearch(nums, k, nums.size(), nums[i] + nums[j]);
            res += k - j - 1;
        }
    }
    return res;
}

int main() {
    vector<int> nums{2, 2, 3, 4};
    cout << triangleNumber(nums) << endl;
}