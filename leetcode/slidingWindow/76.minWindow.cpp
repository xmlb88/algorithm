#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

string minWindow(string s, string t) {
    unordered_map<char, int> need, window;
    for (char c : t) {
        need[c]++;
    }

    int left = 0, right = 0;
    int valid = 0;
    int start = 0, length = INT_MAX;
    while (right < s.size()) {
        char c = s[right];
        if (need.count(c)) {
            window[c]++;
            if (window[c] == need[c]) valid++;
        }
        right++;

        while (valid == need.size()) {
            if (right - left < length) {
                start = left;
                length = right - left;
            }
            char t = s[left];
            if (need.count(t)) {
                window[t]--;
                if (window[t] < need[t]) valid--;
            }
            left++;
        }
    }
    return length == INT_MAX ? "" : s.substr(start, length);
}