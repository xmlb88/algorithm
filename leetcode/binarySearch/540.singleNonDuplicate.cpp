#include <iostream>
#include <vector>
using namespace std;

// int singleNonDuplicate(vector<int>& nums) {
//     int i = 0;
//     for (int num : nums) {
//         i ^= num;
//     }
//     return i;
// }

// wa own thought
int singleNonDuplicate(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return nums[0];
    int left = 0, right = n;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (mid == 0 && nums[mid] != nums[mid + 1]) return nums[mid];
        if (mid == n - 1 && nums[mid] != nums[mid - 1]) return nums[mid];
        if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]) return nums[mid];

        if ((nums[mid] == nums[mid + 1] && (mid & 1)) || (nums[mid] == nums[mid - 1] && !(mid & 1))) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return nums[left];
}

int main() {
    vector<int> nums{1,1,2,3,3,4,4,8,8};
    cout << singleNonDuplicate(nums) << endl;
}

// solution2
// 利用right - mid得到右边个数的奇偶
int singleNonDuplicate(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        bool halvesAreEven = (right - mid) % 2 == 0;

        if (nums[mid + 1] == nums[mid]) {
            if (halvesAreEven) {
                left = mid + 2;
            } else {
                right = mid - 1;
            }
        } else if (nums[mid - 1] == nums[mid]) {
            if (halvesAreEven) {
                right = mid - 2;
            } else {
                left = mid + 1;
            }
        } else {
            return nums[mid];
        }
    }
    return nums[left];
}

// solution3
// 直接对偶数索引二分
int singleNonDuplicate(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (mid & 1) --mid;
        if (nums[mid] == nums[mid + 1]) {
            left = mid + 2;
        } else right = mid;
    }
    return nums[left];
}