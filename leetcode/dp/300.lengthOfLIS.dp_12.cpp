#include<iostream>
#include <vector>
using namespace std;

int lengthOfLIS(vector<int>& nums) {
    vector<int> dp(nums.size(), 1);
    for (int i = 0; i < nums.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (nums[j] < nums[i])
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }

    int result = 0;
    for (int res : dp) {
        result = max(result, res);
    }

    return result;
}

int lengthOfLIS(vector<int>& nums) {
    vector<int> dp(nums.size(), 1);

    for (int i = 0; i < nums.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (nums[j] < nums[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    int result = 0;
    for (int res : dp) {
        result = max(result, res);
    }
    return result;
}


// review 2020年11月18日11:30:11
int lengthOfLIS(vector<int>& nums) {
    vector<int> dp(nums.size(), 1);
    
    for (int i = 0; i < nums.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (nums[j] < nums[i]) {
                dp[i] = max(dp[i], dp[j] +1);
            }
        }
    }

    int result = 0;
    for (int res : dp) {
        result = max(result, res);
    }
    return result;
}

// review
int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 1);
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    int res = INT_MIN;
    for (int i = 0; i < n; i++) {
        res = max(res, dp[i]);
    }
    return res;
}


int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 1);
    int res = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        res = max(res, dp[i]);
    }

    return res;
}


int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 1);
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    int res = 1;
    for (int i = 0; i < n; i++) {
        res = max(res, dp[i]);
    }

    return res;
}

// 二分 + 贪心
int lengthOfLIS(vector<int>& nums) {
    vector<int> minnums;
    for (int v : nums) {
        if (minnums.empty() || v > minnums.back()) {
            minnums.push_back(v);
        } else {
            *upper_bound(minnums.begin(), minnums.end(), v) = v;
        }
    }
    return minnums.size();
}

int lengthOfLIS(vector<int>& nums) {
    vector<int> minnum;
    for (int v : nums) {
        if (minnum.empty() || v > minnum.back()) {
            minnum.push_back(v);
        } else {
            int left = 0, right = minnum.size() - 1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (minnum[mid] == v) {
                    right = mid - 1;
                } else if (minnum[mid] < v) {
                    left = mid + 1;
                } else if (minnum[mid] > v) {
                    right = mid - 1;
                }
            }
            minnum[left] = v;
        }
    }

    return minnum.size();
}