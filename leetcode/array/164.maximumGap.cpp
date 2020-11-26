#include <iostream>
#include <vector>
#include <set>
using namespace std;

// 暴力
int maximumGap(vector<int>& nums) {
    if (nums.size() < 2) return 0;
    sort(nums.begin(), nums.end());
    int gap = 0;
    for (int i = 0; i < nums.size() - 1; i++) {
        gap = max(gap, nums[i + 1] - nums[i]);
    }

    return gap;
}

// 基数排序
// 342 58 576 356
int maximumGap(vector<int>& nums) {
    int n = nums.size();
    if (n < 2) return 0;

    int exp = 1;
    vector<int> buf(n);
    int maxval = *max_element(nums.begin(), nums.end());

    while (maxval >= exp) {
        vector<int> cnt(10);
        for (int i = 0; i < n; i++) {
            int digit = (nums[i] / exp) % 10;
            cnt[digit]++;
        }

        for (int i = 1; i < 10; i++) {
            cnt[i] += cnt[i - 1];
        }

        for (int i = n - 1; i >= 0; i--) {
            int digit = (nums[i] / exp) % 10;
            buf[cnt[digit] - 1] = nums[i];
            cnt[digit]--;
        }

        copy(buf.begin(), buf.end(), nums.begin());
        exp *= 10;
    }

    int ret = 0;
    for (int i = 1; i < n; i++) {
        ret = max(ret, nums[i] - nums[i - 1]);
    }
    return ret;
}

// 桶排序
// 1, 4, 7, 10, 14, 16, 18, 20, 25, 28
// d = (28 - 1) / (10 - 1) = 3
// bucketSize = (28 - 1) / 3 + 1 = 10
// [1, 4)  [4, ]
int maximumGap(vector<int>& nums) {
    int n = nums.size();
    if (n < 2) return 0;

    int minVal = *min_element(nums.begin(), nums.end());
    int maxVal = *max_element(nums.begin(), nums.end());
    int d = max(1, (maxVal - minVal) / (n - 1));
    int bucketSize = (maxVal - minVal) / d + 1;

    // 存储（桶内最小值，桶内最大值）对，（-1，-1）表示桶为空
    vector<pair<int, int>> bucket(bucketSize, {-1, -1});
    for (int i = 0; i < n; i++) {
        int idx = (nums[i] - minVal) / d;
        if (bucket[idx].first == -1) {
            bucket[idx].first = bucket[idx].second = nums[i];
        } else {
            bucket[idx].first = min(bucket[idx].first, nums[i]);
            bucket[idx].second = max(bucket[idx].second, nums[i]);
        }
    }

    int ret = 0;
    int prev = -1;
    for (int i = 0; i < bucketSize; i++) {
        if (bucket[i].first == -1) continue;
        if (prev != -1) {
            ret = max(ret, bucket[i].first - bucket[prev].second);
        }
        prev = i;
    }
    return ret;
}