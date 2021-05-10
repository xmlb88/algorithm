#include <iostream>
#include <vector>
using namespace std;

int findKthPositive(vector<int>& arr, int k) {
    int i = 0;
    int num = 1;
    int idx = 0;
    while (i < k) {
        if (idx < arr.size() && arr[idx] == num) {
            ++idx;
        } else {
            ++i;
            if (i == k) return num;
        }
        ++num;
    }
    return -1;
}

// https://leetcode-cn.com/problems/kth-missing-positive-number/solution/di-k-ge-que-shi-de-zheng-zheng-shu-by-leetcode-sol/
// Ã¶¾Ù

int findKthPositive(vector<int>& arr, int k) {
    int missCount = 0, lastMiss = -1, current = 1, ptr = 0;
    for (;missCount < k; ++current) {
        if (current == arr[ptr]) {
            ptr = (ptr + 1 < arr.size()) ? ptr + 1 : ptr;
        } else {
            ++missCount;
            lastMiss = current;
        }
    }
    return lastMiss;
}

int findKthPositive(vector<int>& arr, int k) {
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] <= k) ++k;
    }
    return k;
}

// arr = [2,3,4,7,11], k = 5
int findKthPositive(vector<int>& arr, int k) {
    int i, n = arr.size();
    for (i = 0; i < n; ++i) {
        if (arr[i] - i - 1 >= k) {
            return k + i;
        }
    }
    return k + i;
}

// ¶þ·Ö
int findKthPositive(vector<int>& arr, int k) {
    int left = 0, right = arr.size(), mid = 0;
    while (left < right) {
        mid = left + (right - left) / 2;
        if (arr[mid] - mid - 1 >= k) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return k + left;
}