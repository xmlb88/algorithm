#include <iostream>
#include <vector>
#include <string>
using namespace std;

// WA
string largestNumber(vector<int>& nums) {
    vector<string> snums;
    for (auto num : nums) {
        snums.push_back(to_string(num));
    }

    sort(snums.begin(), snums.end(), [](const string& s1, const string& s2) {
        return s1 + s2 > s2 + s1;
    });

    string res = "";
    for (auto& s : snums) {
        res += s;
    }
    if (res == string(res.size(), '0')) return "0";
    return res;
}


// https://leetcode-cn.com/problems/largest-number/solution/zui-da-shu-by-leetcode-solution-sid5/
// 

// 35 3
string largestNumber(vector<int>& nums) {
    sort(nums.begin(), nums.end(), [](const int& x, const int& y) {
        long sx = 10, sy = 10;
        while (sx <= x) {
            sx *= 10;
        }
        while (sy <= y) {
            sy *= 10;
        }

        return x * sy + y > y * sx + x;
    });

    if (nums[0] == 0) return "0";
    string res;
    for (int& x : nums) {
        res += to_string(x);
    }
    return res;
}