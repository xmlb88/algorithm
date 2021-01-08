#include <iostream>
#include <vector>
using namespace std;

// self thought not good
void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    if (n <= 1) return nums;
    k = k % n;
    vector<int> res(nums.begin() + (n - k), nums.end());
    for (int i = 0; i < n - k; i++) {
        res.push_back(nums[i]);
    }
    nums = res;
}

// 使用额外数组
void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        arr[(i + k) % n] = nums[i];
    }
    nums.assign(arr.begin(), arr.end());
}

// 3次翻转
void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    if (n <= 1) return;
    k = k % n;
    reverse(nums, 0, n - k - 1);
    reverse(nums, n - k, n - 1);
    reverse(nums, 0, n - 1);
}

void reverse(vector<int>& nums, int i, int j) {
    while (i < j) {
        swap(nums[i], nums[j]);
        i++;
        j--;
    }
}

// [1,2,3,4,5,6,7] k = 3
// [1, 2, 3, 4, 7, 6, 5]
// [4, 3, 2, 1, 7, 6, 5]
// [5, 6, 7, 1, 2, 3, 4]

// 环状替换
void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k %= n;
    int count = gcd(n, k);
    for (int i = 0; i < count; i++) {
        int start = i;
        int temp = nums[i];
        do {
            int target = (start + k) % n;
            swap(nums[target], temp);
            start = target;
        } while (i != start);
    }
}