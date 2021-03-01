#include <iostream>
#include <vector>
using namespace std;

class NumArray {
private:
    vector<int> preSum{0};

public:
    NumArray(vector<int>& nums) {
        for (const int& num : nums) {
            int back = preSum.back();
            preSum.push_back(back + num);
        }
    }

    int sumRange(int i, int j) {
        return preSum[j + 1] - preSum[i];
    }
};