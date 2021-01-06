#include <iostream>
#include <vector>
using namespace std;

void moveZeroes(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return;

    int slow = 0, fast = 0;
    while (fast < n) {
        if (nums[fast] != 0) {
            swap(nums[slow], nums[fast]);
            slow++;
        }
        fast++;
    }

    return;
}

// review 2020��11��19��09:15:08
// ����˫ָ��
void moveZeroes(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return;

    int slow = 0, fast = 0;
    while (fast < n) {
        if (nums[fast] != 0) {
            swap(nums[slow], nums[fast]);
            slow++;
        }
        fast++;
    }
    return;
}

void moveZeroes(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return;

    int slow = 0, fast = 0;
    while (fast < n) {
        if (nums[fast] != 0) {
            swap(nums[fast], nums[slow]);
            slow++;
        }
        fast++;
    }
    return;
}