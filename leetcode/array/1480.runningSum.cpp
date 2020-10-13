#include <iostream>
#include <vector>
using namespace std;

vector<int> runningSum(vector<int>& nums) {
    int n = nums.size();
    vector<int> rsum(n);
    rsum[0] = nums[0];
    for (int i = 1; i < n; i++) {
        rsum[i] = rsum[i - 1] + nums[i];
    }

    return rsum;
}