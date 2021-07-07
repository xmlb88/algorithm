#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// TODO:
// int triangleNumber(vector<int>& nums) {
//     if (nums.size() < 3) return 0;
//     int res = 0;
//     sort(nums.begin(), nums.end());
//     for (int i = 0; i < nums.size() - 2; ++i) {
//         for (int j = i + 1; j < nums.size() - 1; ++j) {
//             for (int k = j + 1; k < nums.size(); ++k) {
//                 if (nums[i] + nums[j] > nums[k]) ++res;
//             }
//         }
//     }
//     return res;
// }

// ¶þ·Ö
int binarySearch(vector<int>& nums, int left, int right, int x) {
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] >= x) {
            right = mid;
        } else {
            left = mid + 1;
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

// Ë«Ö¸Õë
int triangleNumber(vector<int>& nums) {
    if (nums.size() < 3) return 0;
    int count = 0;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 2; ++i) {
        int k = i + 2;
        for (int j = i + 1; j < nums.size() - 1; ++j) {
            while (k < nums.size() && nums[i] + nums[j] > nums[k])
                ++k;
            count += (k - j - 1);
        }
    }
    return count;
}

int main() {
    vector<int> nums = {0,1,0,1};
    cout << triangleNumber(nums) << endl;
}