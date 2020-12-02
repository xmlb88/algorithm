#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

// have a try
vector<int> findAnagrams(string s, string p) {
    unordered_map<char, int> need, window;
    for (char c : p) need[c]++;
    int left = 0, right = 0;
    int valid = 0;
    vector<int> res;
    while (right < s.size()) {
        char c = s[right];
        right++;
        if (need.count(c)) {
            window[c]++;
            if (window[c] == need[c]) valid++;
        }

        while (valid == need.size()) {
            // 在这里判断
            if (right - left == p.size()) res.push_back(left);

            char d = s[left];
            left++;
            if (need.count(d)) {
                if (window[d] == need[d]) valid--;
                window[d]--;
            }
        }
    }
    return res;
}

// follow up
vector<int> findAnagrams(string s, string t) {
    unordered_map<char, int> need, window;
    for (char c : t) need[c]++;
    int left = 0, right = 0;
    int valid = 0;
    vector<int> res;
    while (right < s.size()) {
        char c = s[right];
        right++;
        // 进行窗口内数据的一系列更新
        if (need.count(c)) {
            window[c]++;
            if (window[c] == need[c]) valid++;
        }

        // 判断左侧窗口是否要收缩
        while (right - left >= t.size()) {
            // 当窗口符合条件时，把起始索引加入res
            if (valid == need.size()) res.push_back(left);

            char d = s[left];
            left++;
            // 进行窗口内数据的一系列更新
            if (need.count(d)) {
                if (window[d] == need[d]) valid--;
                window[d]--;
            }
        }
    }
    return res;
}