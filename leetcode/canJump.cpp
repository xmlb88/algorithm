#include<iostream>
#include<vector>
using namespace std;

bool canJump(vector<int>& nums) {
    int n = nums.size();
    int farthest = 0;
    for (int i = 0; i < n - 1; i++) {
        // 不断计算能跳到的最远距离
        farthest = max(farthest, i + nums[i]);
        // 可能碰到了0，卡住跳不动
        if (farthest <= i) return false;
    }

    return farthest >= n - 1;
}