#include <iostream>
#include <vector>
using namespace std;

bool threeConsecutiveOdds(vector<int>& nums) {
    if (nums.size() < 3) return false;
    for (int i = 0; i < nums.size() - 2; i++) {
        if (nums[i] % 2 == 0) continue;
        else if (nums[i] % 2 != 0) {
            if (nums[i + 1] % 2 != 0 && nums[i + 2] % 2 != 0) return true;
        }
    }

    return false;
}