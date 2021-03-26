#include <iostream>
#include <vector>
using namespace std;

violence
int missingElement(vector<int>& nums, int k) {
    int n = nums.size();
    int start = nums[0], end = nums[n - 1];
    for (int i = start + 1; k > 0; ++i) {
        if (find(nums.begin(), nums.end(), i) == nums.end()) {
            if (--k == 0) {
                return i;
            }
        }
    }
    return -1;
}

// [1, 2, 4, 5] k = 3

// 用差值计算相差多少个数 WA
int missingElement(vector<int>& nums, int k) {
    int n = nums.size();
    if (nums[n - 1] - nums[0] - nums.size() + 1 < k) {
        return k + nums[0] + nums.size() - 1;
    }

    int left = 0, right = n;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] - nums[left] - (mid - left) < k) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return nums[left] + k;
}

// 线性扫描
// https://leetcode-cn.com/problems/missing-element-in-sorted-array/solution/you-xu-shu-zu-zhong-de-que-shi-yuan-su-by-leetcode/
//

// 4 7 9 10
// 0 2 3 3
// 应该有A[i] - A[0] + 1个数字，只有i + 1个数字
// missing数组计算: A[i] - A[0] - i
// missing[i - 1] < k <= missing[i]
// 计算结果：A[i - 1] + (k - missing[k - 1])

int missing(vector<int>& nums, int idx) {
    return nums[idx] - nums[0] - idx;
}

int missingElement(vector<int>& nums, int k) {
    int n = nums.size();
    if (k > missing(nums, n - 1)) {
        return nums[n - 1] + (k - missing(nums, n - 1));
    }

    int idx = 1;
    while (missing(nums, idx) < k) idx++;

    return nums[idx - 1] + k - missing(nums, idx - 1);
}

// 二分找missing[i - 1] < k <= missing[i]
int missing(vector<int>& nums, int idx) {
    return nums[idx] - nums[0] - idx;
}

int missingElement(vector<int>& nums, int k) {
    int n = nums.size();
    
    if (missing(nums, n - 1) < k) {
        return nums[n - 1] + k - missing(nums, n - 1);
    }

    int left = 0, right = n;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (missing(nums, mid) >= k) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return nums[left - 1] + k - missing(nums, left - 1);
}

int main() {
    vector<int> nums{4, 7, 9, 10};
    cout << missingElement(nums, 1) << endl;
}