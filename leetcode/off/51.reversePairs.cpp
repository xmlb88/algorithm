#include <iostream>
#include <vector>
using namespace std;

// try ±©Á¦
int reversePairs(vector<int>& nums) {
    if (nums.empty()) return 0;
    int count = 0;
    for (int i = 0; i < nums.size() - 1; i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[i] > nums[j]) count++;
        }
    }
    return count;
}

// ¹é²¢
// TODO:
