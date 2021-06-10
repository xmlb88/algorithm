#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

// int solve(vector<int>& nums) {
//     int n = nums.size();
//     int count = 0;
//     for (int i = 0; i < n; ++i) {
//         for (int j = i + 1; j < n; ++j) {
//             if (nums[i] > nums[j] * 3) ++count;
//         }
//     }
//     return count;
// }


// ·ÖÖÎ

void print(vector<int>& nums) {
    for (int n : nums) {
        cout << n << " ";
    }
    cout << endl;
}

// int cnt = 0;
// vector<int> temp;
// void merge(vector<int>& nums, int left, int right) {
//     int mid = left + (right - left) / 2;
//     int l = left, r = mid + 1;
//     while (l <= mid && r <= right) {
//         if (nums[l] <= nums[r] * 3) {
//             ++l;
//         } else {
//             cnt += mid - l + 1;
//             ++r;
//         }
//     }

//     l = left, r = mid + 1;
//     while (l <= mid && r <= right) {
//         if (nums[l] <= nums[r]) {
//             temp.push_back(nums[l]);
//             ++l;
//         } else {
//             temp.push_back(nums[r]);
//             ++r;
//         }
//     }

//     while (l <= mid) temp.push_back(nums[l++]);
//     while (r <= right) temp.push_back(nums[r++]);

//     for (int i = left; i <= right; ++i) {
//         nums[i] = temp[i - left];
//     }
//     temp.clear();
// }

// void mergeSort(vector<int>& nums, int left, int right) {
//     if (left >= right) return;
//     int mid = left + (right - left) / 2;
//     mergeSort(nums, left, mid);
//     mergeSort(nums, mid + 1, right);
//     merge(nums, left, right);
// }

// int solve(vector<int>& nums) {
//     mergeSort(nums, 0, nums.size() - 1);
//     return cnt;
// }




vector<int> temp;
int cnt = 0;

void merge(vector<int>& nums, int left, int right) {
    int mid = left + (right - left) / 2;
    int l = left, r = mid + 1;
    while (l <= mid && r <= right) {
        if (nums[l] <= nums[r] * 3) {
            ++l;
        } else {
            cout << mid << " " << l << endl;
            cnt += mid - l + 1;
            ++r;
        }
    }

    l = left, r = mid + 1;
    int k = left;
    while (l <= mid && r <= right) {
        if (nums[l] <= nums[r]) temp[k++] = nums[l++];
        else temp[k++] = nums[r++];
    }

    while (l <= mid) temp[k++] = nums[l++];
    while (r <= right) temp[k++] = nums[r++];

    for (int i = left; i <= right; ++i) {
        nums[i] = temp[i];
    }

}

void mergeSort(vector<int>& nums, int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSort(nums, left, mid);
    mergeSort(nums, mid + 1, right);
    merge(nums, left, right);
}

int solve(vector<int>& nums) {
    int n = nums.size();
    temp.resize(n, 0);
    mergeSort(nums, 0, n - 1);
    return cnt;
}

int main() {
    vector<int> nums = {1, 1};
    cout << solve(nums) << endl;
    // print(nums);
}