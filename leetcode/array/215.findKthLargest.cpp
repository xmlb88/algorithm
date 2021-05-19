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


// review 2021年5月19日11:36:52
// 小顶堆
int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> p;
    for (int& num : nums) {
        if (p.size() < k) {
            p.push(num);
        } else {
            if (num > p.top()) {
                p.pop();
                p.push(num);
            }
        }
    }
    return p.top();
}

// 排序
int partition(vector<int>& nums, int left, int right) {
    srand(time(NULL));
    int len = right - left + 1;
    int kindex = rand() % len + left;
    swap(nums[left], nums[kindex]);

    int key = nums[left], i = left, j = right;
    while (i < j) {
        while (nums[j] <= key && i < j) --j;
        if (i < j) nums[i] = nums[j];
        while (nums[i] > key && i < j) ++i;
        if (i < j) nums[j] = nums[i];
    }
    nums[i] = key;
    return i;
}

int QuickSortPartition(vector<int>& nums, int k, int left, int right) {
    int pos = partition(nums, left, right);
    if (pos == k - 1) return nums[pos];
    else if (pos < k - 1) return QuickSortPartition(nums, k, pos + 1, right);
    return QuickSortPartition(nums, k, left, pos - 1);
}

int findKthLargest(vector<int>& nums, int k) {
    return QuickSortPartition(nums, k, 0, nums.size() - 1);
}