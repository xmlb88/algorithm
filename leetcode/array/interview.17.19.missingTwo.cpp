#include <iostream>
#include <vector>
using namespace std;

vector<int> missingTwo(vector<int>& nums) {
    int n = nums.size() + 2;
    int x = 0;
    for (int i = 0; i < nums.size(); ++i) {
        x ^= nums[i];
    }

    for (int i = 1; i <= n; ++i) {
        x ^= i;
    }

    int num = x & (-x);
    int xo = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] & num) {
            xo ^= nums[i];
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (i & num) {
            xo ^= i;
        }
    }

    return {xo, xo ^ x};
    
}