#include <iostream>
#include <vector>
using namespace std;

bool checkPossibility(vector<int>& nums) {
    int count = 0;
    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i] < nums[i - 1]) {
            if (count) return false;

            count++;
            if (i == 1 || nums[i] >= nums[i - 2]) {
                nums[i - 1] = nums[i];
            } else nums[i] = nums[i - 1];
        }
    }
    return true;
}

bool checkPossibility(vector<int>& nums) {
    int count = 0;
    for (int i = 0; i < nums.size() - 1; ++i) {
        if (nums[i] > nums[i + 1]) {
            if (count) return false;

            ++count;
            if (i > 0 && nums[i + 1] < nums[i - 1]) {
                nums[i + 1] = nums[i];
            }
        }
    }
    return true;
}
