#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    int size = nums.size();
    int i = 0;
    while (i < size - 2) {
        if (nums[i] == nums[i + 1] && nums[i] == nums[i + 2]) {
            for (int j = i + 2; j < size - 1; ++j) {
                nums[j] = nums[j + 1];
            }
            --size;
        } else ++i;
    }
    return size;
}


int removeDuplicates(vector<int>& nums) {
    int n = nums.size();
    if (n <= 2) return n;
    int slow = 2, fast = 2;
    
    while (fast < n) {
        if (nums[slow - 2] != nums[fast]) {
            nums[slow] = nums[fast];
            ++slow;
        }
        ++fast;
    }
    
    return slow;
}

// [0,0,1,1,1,1,2,3,3]

