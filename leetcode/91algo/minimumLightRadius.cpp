#include <iostream>
#include <vector>
using namespace std;

bool check(vector<int>& nums, double radius) {
    vector<int> light_start;
    light_start.push_back(nums[0]);
    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i] <= light_start.back() + 2 * radius) continue;
        else if (light_start.size() == 3) return false;
        else light_start.push_back(nums[i]);
    }

    return true;
}

double solve(vector<int>& nums) {
    if (nums.size() <= 3) return 0;
    sort(nums.begin(), nums.end());
    double left = 0, right = (nums.back() - nums[0]) / 3.0;
    double last = right, mid = left + (right - left) / 2.0;
    for (int i = 0; i < 40; ++i) {
        mid = left + (right - left) / 2.0;
        if (check(nums, mid)) {
            last = mid;
            right = mid;
        } else left = mid;
    }
    return left;
}


int check(vector<int>& nums, double radius) {
    int i = 0, count = 0;
    while (i < nums.size()) {
        ++count;
        int start = nums[i];
        while (i < nums.size() && nums[i] <= start + 2 * radius) ++i;
    }
    return count;
}

double solve(vector<int>& nums) {
    if (nums.size() <= 3) return 0;
    sort(nums.begin(), nums.end());
    double left = 0, right = (nums.back() - nums[0]) / 3.0;
    while (fabs(left - right) > 1e-7) {
        double mid = left + (right - left) / 2;
        if (check(nums, mid) <= 3) {
            right = mid;
        } else left = mid;
    }
    return left;
}