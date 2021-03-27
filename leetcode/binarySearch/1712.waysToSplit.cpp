#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int waysToSplit(vector<int>& nums) {
    int n = nums.size();
    vector<int> v(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        v[i + 1] = v[i] + nums[i];
    }

    long long ret = 0;
    const int M = 1e9 + 7;

    for (int i = 1; i < n; ++i) {
        // 特判
        if (v[i] * 3 > v[n]) break;

        // 第一次二分找右边界
        int l = i + 1, r = n - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (v[n] - v[mid] >= v[mid] - v[i]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        // 第二次二分找左边界
        int ll = i + 1, rr = n - 1;
        while (ll <= rr) {
            int mid = ll + (rr - ll) / 2;
            if (v[mid] - v[i] >= v[i]) {
                rr = mid - 1;
            } else {
                ll = mid + 1;
            }
        }
        ret += r - ll + 1;
    }
    return ret % M;
}