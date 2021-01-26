#include<iostream>
#include<vector>
using namespace std;

int rob(vector<int>& nums) {
    if (nums.size() == 0) return 0;
    if (nums.size() == 1) return nums[0];
    
    vector<int>nums1(nums.begin(), nums.end() - 1);
    vector<int>nums2(nums.begin() + 1, nums.end());
    return max(rob2(nums1), rob2(nums2));
}

int rob2(vector<int>& nums) {
    if (nums.size() == 0) return 0;
    if (nums.size() == 1) return nums[0];

    int dp_1 = nums[0];
    int dp_2 = max(nums[0], nums[1]);

    int result = dp_2;
    for (int i = 2; i < nums.size(); i++) {
        result = max(dp_2, dp_1 + nums[i]);
        dp_1 = dp_2;
        dp_2 = result;
    }

    return result;
}

// review 2021Äê1ÔÂ5ÈÕ20:45:49
int rob(vector<int>& nums) {
    if (nums.size() == 0) return 0;
    if (nums.size() == 1) return nums[0];
    vector<int> nums1(nums.begin(), nums.end() - 1);
    vector<int> nums2(nums.begin() + 1, nums.end());
    return max(rob2(nums1), rob2(nums2));
}

int rob2(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    if (n == 1) return nums[0];
    int dp_1 = nums[0], dp_2 = max(nums[0], nums[1]);
    for (int i = 2; i < n; i++) {
        int temp = max(dp_2, dp_1 + nums[i]);
        dp_1 = dp_2;
        dp_2 = temp;
    }
    return dp_2;
}