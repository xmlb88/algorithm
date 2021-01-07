#include <iostream>
#include <vector>
using namespace std;

// wrong answer
// vector<int> largestDivisibleSubset(vector<int>& nums) {
//     int n = nums.size();
//     if (n <= 1) return nums;
//     sort(nums.begin(), nums.end());
//     vector<int> res;
//     for (int i = 0; i < n; i++) {
//         vector<int> subset = {nums[i]};
//         for (int j = i + 1; j < n; j++) {
//             if (nums[j] % subset.back() == 0) {
//                 subset.push_back(nums[j]);
//             }
//         }
//         if (subset.size() > res.size()) {
//             res = subset;
//         }
//     }
//     return res;
// }

// dp
vector<int> largestDivisibleSubset(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return {};
    vector<vector<int>> dp(n);
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++) {
        vector<int> maxSubset;
        for (int k = 0; k < i; k++) {
            if (nums[i] % nums[k] == 0 && maxSubset.size() < dp[k].size()) {
                maxSubset = dp[k];
            }
        }
        dp[i] = maxSubset;
        dp[i].push_back(nums[i]);
    }

    vector<int> res;
    for (int i = 0; i < n; i++) {
        if (res.size() < dp[i].size()) res = dp[i];
    }
    return res;
}

// ÓÅ»¯¿Õ¼ä
vector<int> largestDivisibleSubset(vector<int>& nums) {
    int n = nums.size();
    if (n <= 1) return nums;
    sort(nums.begin(), nums.end());
    vector<int> dp(n, 1);
    vector<int> last(n, -1);
    int sign = -1, maxlen = 0;
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < i; k++) {
            if (nums[i] % nums[k] == 0 && dp[i] < dp[k] + 1) {
                dp[i] = dp[k] + 1;
                last[i] = k;
            }
            if (dp[i] > maxlen) {
                maxlen = dp[i];
                sign = i;
            }
        }
    }

    vector<int> res;
    while (sign != -1) {
        res.push_back(nums[sign]);
        sign = last[sign];
    }
    return res;
}
