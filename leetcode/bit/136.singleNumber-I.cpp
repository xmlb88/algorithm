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