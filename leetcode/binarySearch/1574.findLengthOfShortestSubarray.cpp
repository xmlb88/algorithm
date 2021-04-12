#include <iostream>
#include <vector>
#include <deque>
using namespace std;

// [1,2,3,10,4,2,3,5]
// TLE
bool is_sort(deque<int>& dq) {
    int n = dq.size();
    if (n <= 1) return true;
    bool flag = true;
    for (int i = 0; i < n - 1; ++i) {
        if (dq[i] > dq[i + 1]) {
            flag = false;
            break;
        }
    }
    return flag;
}

bool check(vector<int>& arr, int len) {
    int i = -1, j = len;
    while (j <= arr.size()) {
        deque<int> dq;
        for (int front = i; front >= 0; --front) {
            dq.push_front(arr[front]);
        }
        for (int back = j; back < arr.size(); ++back) {
            dq.push_back(arr[back]);
        }
        if (is_sort(dq)) return true;
        ++i;
        ++j;
    }
    return false;
}

int findLengthOfShortestSubarray(vector<int>& arr) {
    int n = arr.size();
    if (n <= 1) return 0;

    int left = 0, right = n;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (check(arr, mid)) {
            right = mid;
        } else left = mid + 1;
    }
    return left;
}

int main() {
    vector<int> arr{1,2,3,10,4,2,3,5};
    cout << findLengthOfShortestSubarray(arr) << endl;
}

// https://leetcode-cn.com/problems/shortest-subarray-to-be-removed-to-make-array-sorted/solution/cji-hu-shuang-bai-de-jie-fa-xiang-xi-fen-2enx/
// 

int findLengthOfShortestSubarray(vector<int>& arr) {
    int n = arr.size();
    if (n <= 1) return 0;

    // [0 ... left] 有序
    int left = 0;
    while (left + 1 < n && arr[left] <= arr[left + 1]) {
        ++left;
    }
    if (left == n - 1) return 0;

    // [right ... n - 1] 有序
    int right = n - 1;
    while (right > 0 && arr[right - 1] <= arr[right]) {
        --right;
    }

    // 完全删除一边[left + 1, n - 1]， 或者[0, right - 1]
    int result = min(n - left - 1, right);

    // 左边，右边各保留一部分
    int i = 0, j = right;
    while (i <= left && j <= n - 1) {
        // [0 ... i]和[j .. n - 1]有序， 删除[i + 1, j - 1]
        if (arr[i] <= arr[j]) {
            result = min(result, j - i - 1);
            i++;
        } else {
            j++;
        }
    }
    return result;
}

// TODO: