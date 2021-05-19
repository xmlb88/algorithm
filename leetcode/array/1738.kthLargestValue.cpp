#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// 二维前缀和 + 堆
// priority_queue<int, vector<int>, greater<int>> 小顶堆
// priority_queue<int, vector<int>, less<int>> 默认 大顶堆
int kthLargestValue(vector<vector<int>>& matrix, int k) {
    int n = matrix.size(), m = matrix[0].size();
    vector<vector<int>> prexor(n, vector<int> (m));
    prexor[0][0] = matrix[0][0];

    for (int i = 1; i < n; ++i) {
        prexor[i][0] = prexor[i - 1][0] ^ matrix[i][0];
    }

    for (int j = 1; j < m; ++j) {
        prexor[0][j] = prexor[0][j - 1] ^ matrix[0][j];
    }

    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            prexor[i][j] = prexor[i - 1][j] ^ prexor[i][j - 1] ^ prexor[i - 1][j - 1] ^ matrix[i][j];
        }
    }

    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (q.size() < k) {
                q.push(prexor[i][j]);
            } else {
                if (prexor[i][j] > q.top()) {
                    q.pop();
                    q.push(prexor[i][j]);
                }
            }
        }
    }
    return q.top();
}

// 优化
int kthLargestValue(vector<vector<int>>& matrix, int k) {
    int n = matrix.size(), m = matrix[0].size();
    vector<vector<int>> prexor(n + 1, vector<int> (m + 1, 0));
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            prexor[i][j] = prexor[i - 1][j] ^ prexor[i][j - 1] ^ prexor[i - 1][j - 1] ^ matrix[i - 1][j - 1];
            if (q.size() < k) {
                q.push(prexor[i][j]);
            } else if (prexor[i][j] > q.top()) {
                q.pop();
                q.push(prexor[i][j]);
            }
        }
    }
    return q.top();
}

// 直接排序
int kthLargestValue(vector<vector<int>>& matrix, int k) {
    int n = matrix.size(), m = matrix[0].size();
    vector<vector<int>> prexor(n + 1, vector<int> (m + 1, 0));
    vector<int> res;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            prexor[i][j] = prexor[i - 1][j] ^ prexor[i][j - 1] ^ prexor[i - 1][j - 1] ^ matrix[i - 1][j - 1];
            res.push_back(prexor[i][j]);
        }
    }
    sort(res.begin(), res.end(), greater<int>());
    return res[k - 1];
}

// 快速排序
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

void quickSortPartition(vector<int>& nums, int k, int left, int right) {
    int pos = partition(nums, left, right);
    if (pos == k - 1) return;
    else if (pos < k - 1) quickSortPartition(nums, k, pos + 1, right);
    else if (pos > k - 1) quickSortPartition(nums, k, left, pos - 1);
}

int kthLargestValue(vector<vector<int>>& matrix, int k) {
    int n = matrix.size(), m = matrix[0].size();
    vector<vector<int>> prexor(n + 1, vector<int> (m + 1, 0));
    vector<int> vec;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            prexor[i][j] = prexor[i - 1][j] ^ prexor[i][j - 1] ^ prexor[i - 1][j - 1] ^ matrix[i - 1][j - 1];
            vec.push_back(prexor[i][j]);
        }
    }

    quickSortPartition(vec, k, 0, vec.size() - 1);
    return vec[k - 1];
}