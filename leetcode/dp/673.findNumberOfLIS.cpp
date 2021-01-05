#include <iostream>
#include <vector>
using namespace std;

int findNumberOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 1);
    vector<int> count(n, 1);
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                if (dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    count[i] = count[j];
                } else if (dp[j] + 1 == dp[i]) {
                    count[i] += count[j];
                }
            }
        }
    }

    int max_length = *max_element(dp.begin(), dp.end());
    int number = 0;
    for (int i = 0; i < n; i++) {
        if (dp[i] == max_length) {
            number += count[i];
        }
    }
    return number;
}



int findNumberOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 1);
    vector<int> count(n, 1);
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                if (dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    count[i] = count[j];
                } else if (dp[j] + 1 == dp[i]) {
                    count[i] += count[j];
                }
            }
        }
    }

    int res = 0;
    int max_length = *max_element(dp.begin(), dp.end());
    for (int i = 0; i < n; i++) {
        if (dp[i] == max_length) res += count[i];
    }

    return res;
}