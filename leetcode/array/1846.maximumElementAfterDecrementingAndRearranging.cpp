#include <iostream>
#include <vector>
using namespace std;

// ÅÅÐò + Ì°ÐÄ
int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
    int n = arr.size();
    sort(arr.begin(), arr.end());
    arr[0] = 1;
    for (int i = 0; i < n - 1; ++i) {
        arr[i + 1] = min(arr[i + 1], arr[i] + 1);
    }
    return arr[n - 1];
}

// ¼ÆÊýÅÅÐò
int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
    int n = arr.size();
    vector<int> cnt(n + 1);
    for (int num : arr) {
        if (num >= n) ++cnt[n];
        else ++cnt[num];
    }

    int index = 0;
    for (int i = 1; i <= n; ++i) {
        while (cnt[i] > 0) {
            arr[index++] = i;
            --cnt[i];
        }
    }

    arr[0] = 1;
    for (int i = 1; i < n; ++i) {
        arr[i] = min(arr[i], arr[i - 1] + 1);
    }

    return arr[n - 1];
}

// https://leetcode-cn.com/problems/maximum-element-after-decreasing-and-rearranging/solution/jian-xiao-he-zhong-xin-pai-lie-shu-zu-ho-mzee/

int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
    int n = arr.size();
    vector<int> cnt(n + 1);
    for (int v : arr) {
        ++cnt[min(v, n)];
    }

    int miss = 0;
    for (int i = 1; i <= n; ++i) {
        if (cnt[i] == 0) {
            ++miss;
        } else {
            miss -= min(miss, cnt[i] - 1);
        }
    }
    return n - miss;
}