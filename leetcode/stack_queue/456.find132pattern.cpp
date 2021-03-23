#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// ±©Á¦
bool find132pattern(vector<int>& nums) {
    if (nums.size() < 3) return false;
    for (int i = 0; i < nums.size() - 2; ++i) {
        for (int j = i + 1; j < nums.size() - 1; ++j) {
            for (int k = j + 1; k < nums.size(); ++k) {
                if (nums[i] < nums[k] && nums[k] < nums[j]) {
                    return true;
                }
            }
        }
    }
    return false;
}

bool find132pattern(vector<int>& nums) {
    
}