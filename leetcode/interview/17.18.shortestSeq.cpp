#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// 滑动窗口
vector<int> shortestSeq(vector<int>& big, vector<int>& small) {
    unordered_map<int, int> need, window;
    for(int number : small) {
        need[number]++;
    }

    int left = 0, right = 0;
    int valid = 0;
    int length = INT_MAX;
    vector<int> res;
    while (right < big.size()) {
        // 右移窗口
        int number = big[right];
        right++;
        if (need.count(number)) {
            window[number]++;
            if (window[number] == need[number]) valid++;
        }

        while (valid == need.size()) {
            if (right - left < length) {
                length = right - left;
                res = {left, right - 1};
            }

            int left_num = big[left];
            if (need.count(left_num)) {
                window[left_num]--;
                if (window[left_num] < need[left_num]) valid--;
            }
            left++;
        }
    }
    return res;
}