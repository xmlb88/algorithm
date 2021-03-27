#include <iostream>
#include <vector>
using namespace std;

int minimumSize(vector<int>& nums, int maxOperations) {
    int left = 1, right = *max_element(nums.begin(), nums.end());
    int ans = 0;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int ops = 0;
        for (int x : nums) {
            ops += (x - 1) / mid;
        }

        if (ops <= maxOperations) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return ans;
}

bool check(vector<int>& nums, int cost, int maxOperations) {
    int ans = 0;
    for (int x : nums) {
        ans += (x - 1) / cost;
    }
    return ans <= maxOperations;
}

int minimumSize(vector<int>& nums, int maxOperations) {
    int left = 1, right = *max_element(nums.begin(), nums.end());
    int ans = 0;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (check(nums, mid, maxOperations)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return ans;
}