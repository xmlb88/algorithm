#include <iostream>
#include <vector>
using namespace std;

// wrong
// 只能求无重复数字
int search(vector<int>& arr, int target) {
    if (arr.empty()) return -1;
    int l = 0, r = arr.size() - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == target) return mid;
        // 左半边有序
        if (arr[l] < arr[mid]) {
            if (arr[l] <= target && target <= arr[mid]) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        } else { // 右半边有序
            if (arr[mid] <= target && target <= arr[r]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
    }
    return 0;
}

// 有重复数字
// wrong answer
// int search(vector<int>& arr, int target) {
//     return search(arr, target, 0, arr.size() - 1);
// }

// int search(vector<int>& arr, int target, int left, int right) {
//     if (right < left) return -1;
//     int mid = left + (right - left) / 2;
//     if (target == arr[mid]) {
//         return mid;
//     }
    

//     if (arr[left] < arr[mid]) {
//         if (target >= arr[left] && target < arr[mid]) {
//             return search(arr, target, left, mid - 1);
//         } else {
//             return search(arr, target, mid + 1, right);
//         }
//     } else if (arr[mid] < arr[left]) {
//         if (target > arr[mid] && target <= arr[right]) {
//             return search(arr, target, mid + 1, right);
//         } else {
//             return search(arr, target, left, mid - 1);
//         }
//     } else if (arr[left] == arr[mid]) {
//         if (arr[mid] != arr[right]) {
//             return search(arr, target, mid + 1, right);
//         } else {
//             int result = search(arr, target, left, mid - 1);
//             if (result == -1) {
//                 return search(arr, target, mid + 1, right);
//             } else {
//                 return result;
//             }
//         }
//     }
//     return -1;
// }

int search(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    if (right == -1) return -1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[left] < nums[mid]) {
            if (nums[left] <= target && target <= nums[mid]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        } else if (nums[left] > nums[mid]) {
            if (nums[mid] <= target && target <= nums[right] && nums[left] > nums[right]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        } else if (nums[left] == nums[mid]) {
            if (nums[left] != target) {
                left++;
            } else {
                right = left;
            }
        }
    }
    return nums[left] == target ? left : -1;
}