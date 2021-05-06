#include <iostream>
#include <vector>
using namespace std;

int singleNumber(vector<int>& nums) {
    int num = 0;
    for (int n : nums) {
        num ^= n;
    }
    return num;
}

int singleNumber(vector<int>& nums) {
    int res = 0;
    for (int num : nums) {
        res ^= num;
    }
    return res;
}