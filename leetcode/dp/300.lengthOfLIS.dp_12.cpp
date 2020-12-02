#include<iostream>
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


// review 2020Äê11ÔÂ18ÈÕ11:30:11
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