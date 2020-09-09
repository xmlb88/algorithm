#include <iostream>
#include <vector>
using namespace std;

int rob1(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    if (n == 1) return nums[0];

    int dp_i_1 = nums[0];
    int dp_i_2 = max(nums[0], nums[1]);
    int result = dp_i_2;

    for (int i = 2; i < n; i++) {
        result = max(dp_i_2, dp_i_1 + nums[i]);
        dp_i_1 = dp_i_2;
        dp_i_2 = result;
    }

    return result;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6};
    vector<int> nums1(nums.size() - 1);
    vector<int> nums2(nums.size() - 1);

    copy(nums.begin(), nums.end() - 1, nums1.begin());
    cout << "nums1: ";
    for (int num : nums1) {
        cout << num << " ";
    }
    cout << endl << "nums2: ";
    copy(nums.begin() + 1, nums.end(), nums2.begin());
    for (int num : nums2) {
        cout << num << " ";
    }
    cout << endl;
    cout << rob1(nums2) << endl;
    cout << max(rob1(nums1), rob1(nums2)) << endl;
}