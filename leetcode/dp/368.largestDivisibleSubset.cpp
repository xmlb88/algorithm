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

// 优化空间
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


// review 2021年4月23日18:08:28
// WA
vector<int> largestDivisibleSubset(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<int> dp(n, 1);
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[i] % nums[j] == 0)
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }

    int max_number = INT_MIN, size = 0;
    for (int i = 0; i < n; ++i) {
        if (dp[i] > size) {
            size = dp[i];
            max_number = nums[i];
        }
    }

    vector<int> res;
    for (int i = n - 1; i >= 0 && size > 0; --i) {
        if (max_number % nums[i] == 0 && dp[i] == size) {
            res.push_back(nums[i]);
            max_number = nums[i];
            --size;
        }
    }
    return res;
}