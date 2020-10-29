#include <iostream>
#include <vector>
using namespace std;

// TODO: 
// ±©Á¦ ³¬Ê±
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    if (k == 1) return nums;
    vector<int> res;
    for (int i = 0; i <= nums.size() - k; i++) {
        int maxNum = nums[i];
        for (int j = i + 1; j < i + k; j++) {
            maxNum = max(maxNum, nums[j]);
        }
        res.push_back(maxNum);
    }
    return res;
}

// 
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    if (k == 1) return nums;

}