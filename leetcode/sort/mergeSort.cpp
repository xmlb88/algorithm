#include <iostream>
#include <vector>
using namespace std;

// version 1
// void mergeArray(vector<int>& nums, int left, int mid, int right, vector<int>& temp) {
//     int i = left, j = mid + 1, k = left;
//     while (i <= mid && j <= right) {
//         if (nums[i] <= nums[j]) {
//             temp[k++] = nums[i++];
//             continue;
//         }
//         temp[k++] = nums[j++];
//     }

//     while (i <= mid) temp[k++] = nums[i++];
//     while (j <= right) temp[k++] = nums[j++];

//     for (int i = left; i <= right; ++i) {
//         nums[i] = temp[i];
//     }
// }

// void mergeSort(vector<int>& nums, int left, int right, vector<int>& temp) {
//     if (left >= right) return;
//     int mid = left + (right - left) / 2;
//     mergeSort(nums, left, mid, temp);
//     mergeSort(nums, mid+1, right, temp);
//     mergeArray(nums, left, mid, right, temp);
// }

// version 2 ownthought

vector<int> mergeSort(vector<int>& nums, int left, int right) {
    if (left == right) return {nums[left]};
    int mid = left + (right - left) / 2;
    vector<int> lnums = mergeSort(nums, left, mid);
    vector<int> rnums = mergeSort(nums, mid + 1, right);
    vector<int> res;
    int i = 0, j = 0;
    while (i <= lnums.size() - 1 && j <= rnums.size() - 1) {
        if (lnums[i] <= rnums[j]) {
            res.push_back(lnums[i++]);
            continue;
        }
        res.push_back(rnums[j++]);
    }

    while (i <= lnums.size() - 1) res.push_back(lnums[i++]);
    while (j <= rnums.size() - 1) res.push_back(rnums[j++]);
    return res;
}

int main() {
    vector<int> nums{3, 4, 5, 1, 2, 7, 8, 6, 9};
    vector<int> temp = 
    mergeSort(nums, 0, nums.size() - 1);
    for (int i : temp) {
        cout << i << " ";
    }
}

// 34512 7869
// 345 12 78 69
// 34 5 1 2 7 8 6 9
// 3 4 5 12 78 69
// 34 5 12 78 69
// 345 12 78 69
// 12345 6789