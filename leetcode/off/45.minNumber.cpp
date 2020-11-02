#include <iostream>
#include <vector>
using namespace std;

static bool cmp(int a, int b) {
    string a_b = to_string(a) + to_string(b);
    string b_a = to_string(b) + to_string(a);
    return a_b < b_a;
}

string minNumber(vector<int>& nums) {
    sort(nums.begin(), nums.end(), cmp);
    string res;
    for (int num : nums) {
        res += to_string(num);
    }
    return res;
}