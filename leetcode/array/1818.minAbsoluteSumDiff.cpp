#include <iostream>
#include <vector>
#include <set>
using namespace std;

const int mod = 1e9 + 7;
int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    int sum = 0, maxn = 0;

    vector<int> rec(nums1);
    sort(rec.begin(), rec.end());
    for (int i = 0; i < n; ++i) {
        int diff = abs(nums1[i] - nums2[i]);
        sum = (sum + diff) % mod;
        int j = lower_bound(rec.begin(), rec.end(), nums2[i]) - rec.begin();
        if (j < n) {
            maxn = max(maxn, diff - (rec[j] - nums2[i]));
        }

        if (j > 0) {
            maxn = max(maxn, diff - (nums2[i] - rec[j - 1]));
        }
    }

    return (sum - maxn + mod) % mod;
}