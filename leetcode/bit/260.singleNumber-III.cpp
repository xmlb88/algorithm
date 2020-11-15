#include <iostream>
#include <vector>
using namespace std;

vector<int> singleNumber(vector<int>& nums) {
    int x = 0;
    for (int num : nums) {
        x ^= num;
    }

    int div = 1;
    while ((div & x) == 0) {
        div <<= 1;
    }

    int a = 0, b = 0;
    for (int num : nums) {
        if ((div & num) == 0) a ^= num;
        else b ^= num;
    }

    return {a, b};
}