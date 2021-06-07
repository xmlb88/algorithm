#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    int slow = 0, fast = 0;

    while (fast < n) {
        if (nums[fast] != nums[slow]) {
            slow++;
            nums[slow] = nums[fast];
        }
        fast++;
    }
    return slow + 1;
}



int removeDuplicates(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;

    int slow = 0, fast = 0;
    while (fast < n) {
        if (nums[fast] != nums[slow]) {
            slow++;
            nums[slow] = nums[fast];
        }
        fast++;
    }
    return slow + 1;
}

// review 2021年4月6日19:46:47
int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) return 0;
    int fast = 0, slow = 0;
    while (fast < nums.size()) {
        if (nums[slow] == nums[fast]) {
            fast++;
        } else {
            nums[++slow] = nums[fast++];
        }
    }
    return slow + 1;
}
//nums = [0,0,1,1,1,2,2,3,3,4]

int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) return 0;
    int fast = 0, slow = 0;
    while (fast < nums.size()) {
        if (nums[fast] != nums[slow]) {
            nums[++slow] = nums[fast];
        }
        ++fast;
    }
    return slow + 1;
}

// review 2021年4月19日17:52:18
int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) return 0;
    int slow = 0, fast = 0;
    while (fast < nums.size()) {
        if (nums[fast] != nums[slow]) {
            nums[++slow] = nums[fast];
        }
        ++fast;
    }
    return slow + 1;
}


// [0,0,1,1,1,2,2,3,3,4]
// [0,1,2,3,4]

int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) return 0;
    int slow = 0, fast = 0;
    while (fast < nums.size()) {
        if (nums[slow] == nums[fast]) {
            ++fast;
        } else {
            nums[++slow] = nums[fast++];
        }
    }
    return slow + 1;
}

int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) return 0;
    int slow = 0, fast = 0;
    while (fast < nums.size()) {
        if (nums[fast] != nums[slow]) {
            nums[++slow] = nums[fast];
        }
        ++fast;
    }
    return slow + 1;
}

// review 2021年6月4日19:44:42
int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) return 0;
    int i = 0;
    for (int j = 0; j < nums.size(); ++j) {
        if (nums[i] == nums[j]) continue;
        nums[++i] = nums[j];
    }
    return i + 1;
}