#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int singleNumber(vector<int>& nums) {
    unordered_map<int, int> count;
    for (int num : nums) {
        count[num]++;
    }

    for (auto it = count.begin(); it != count.end(); it++) {
        if (it -> second == 1) return (it -> first);
    }
    return -1;
}