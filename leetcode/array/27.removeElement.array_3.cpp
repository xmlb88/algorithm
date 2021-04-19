#include <iostream>
#include <vector>
using namespace std;

int removeElement(vector<int>& nums, int val) {
    int n = nums.size();
    if (n == 0) return 0;

    int slow = 0, fast = 0;
    while (fast < n) {
        if (nums[fast] != val) {
            nums[slow] = nums[fast];
            slow++;
        }
        fast++;
    }
    return slow;
}


// review 2021Äê4ÔÂ19ÈÕ11:23:06
int removeElement(vector<int>& nums, int val) {
    int i = 0, j = 0;
    while (j < nums.size()) {
        if (nums[j] != val) {
            nums[i] = nums[j];
            ++i;
        }
        ++j;
    }
    return i + 1;
}