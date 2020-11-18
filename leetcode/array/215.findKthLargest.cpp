#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// 二叉堆
int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 0; i < nums.size(); i++) {
        if (i < k) {
            q.push(nums[i]);
            continue;
        }

        if (nums[i] >= q.top()) {
            q.pop();
            q.push(nums[i]);
        }
    }

    return q.top();
}


// 快速排序 选择
int findKthLargest(vector<int>& nums, int k) {
    srand((unsigned)time(NULL));
    int n = nums.size() - k;
    quickSortPartition(nums, n, 0, nums.size() - 1);
    return nums[n];
}

void quickSortPartition(vector<int>& nums, int k, int l, int r) {
    if (l >= r) return;
    int pos = randomPartition(nums, l, r);
    if (pos == k) return;
    else if (pos > k) quickSortPartition(nums, k, l, pos - 1);
    else if (pos < k) quickSortPartition(nums, k, pos + 1, r);
}

int randomPartition(vector<int>& nums, int l, int r) {
    int id = rand() % (r - l + 1);
    swap(nums[l], nums[l + id]);
    return quicksort(nums, l, r);
}

int quicksort(vector<int>& nums, int l, int r) {
    int pivot = nums[l];
    while (l < r) {
        while (l < r && nums[r] >= pivot) r--;
        if (l < r) nums[l] = nums[r];
        while (l < r && nums[l] <= pivot) l++;
        if (l < r) nums[r] = nums[l];
    }
    nums[l] = pivot;
    return l;
}