#include <iostream>
#include <vector>
using namespace std;

// try ±©Á¦
int reversePairs(vector<int>& nums) {
    if (nums.empty()) return 0;
    int count = 0;
    for (int i = 0; i < nums.size() - 1; i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[i] > nums[j]) count++;
        }
    }
    return count;
}


// ¹é²¢
// TODO:
// ac own thought
int reverseNum = 0;
void mergeArray(vector<int>& nums, int left, int mid, int right) {
    vector<int> temp;
    int i = left, j = mid + 1;
    while (i <= mid && j <= right) {
        if (nums[i] <= nums[j]) {
            temp.push_back(nums[i++]);
            reverseNum += j - (mid + 1);
            continue;
        }
        temp.push_back(nums[j++]);
    }

    while (i <= mid) {
        temp.push_back(nums[i++]);
        reverseNum += j - (mid + 1);
    }

    while (j <= right) {
        temp.push_back(nums[j++]);
    }

    copy(temp.begin(), temp.end(), nums.begin() + left);
}

void mergeSort(vector<int>& nums, int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSort(nums, left, mid);
    mergeSort(nums, mid + 1, right);
    mergeArray(nums, left, mid, right);
}

int reversePairs(vector<int>& nums) {
    if (nums.size() <= 1) return 0;
    mergeSort(nums, 0, nums.size() - 1);
    return reverseNum;
}

// ¹é²¢2 other write way
int mergeSort(vector<int>& nums, vector<int>& temp, int l, int r) {
    if (l >= r) return 0;
    int mid = l + (r - l) / 2;
    int inv_count = mergeSort(nums, temp, l, mid) + mergeSort(nums, temp, mid + 1, r);
    int i = l, j = mid + 1, pos = l;
    while (i <= mid && j <= r) {
        if (nums[i] <= nums[j]) {
            temp[pos++] = nums[i++];
            inv_count += j - (mid + 1);
            continue;
        }
        temp[pos++] = nums[j++];
    }

    while (i <= mid) {
        temp[pos++] = nums[i++];
        inv_count += j - (mid + 1);
    }

    while (j <= right) {
        temp[pos++] = nums[j++];
    }

    copy(temp.begin() + l, temp.begin() + r + 1, nums.begin() + l);
    return inv_count;
}

int reversePairs(vector<int>& nums) {
    int n = nums.size();
    vector<int> temp(n);
    return mergeSort(nums, temp, 0, n - 1);
}