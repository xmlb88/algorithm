#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

// have a try // ac
bool checkInclusion(string s1, string s2) {
    unordered_map<char, int> need, window;
    for (char c : s1) need[c]++;
    int left = 0, right = 0;
    int valid = 0;
    while (right < s2.size()) {
        char c = s2[right];
        right++;
        if (need.count(c)) {
            window[c]++;
            if (window[c] == need[c]) valid++;
        }

        while (valid == need.size()) {
            if (right - left == s1.size()) return true;

            char d = s2[left];
            left++;
            if (need.count(d)) {
                if (window[d] == need[d]) valid--;
                window[d]--;
            }
        }
    }
    return false;
}

// follow up
bool checkInclusion(string t, string s) {
    unordered_map<char, int> need, window;
    for (char c : t) need[c]++;
    int left = 0, right = 0;
    int valid = 0;
    while (right < s.size()) {
        char c = s[right];
        right++;
        if (need.count(c)) {
            window[c]++;
            if (window[c] == need[c]) valid++;
        }

        while (right - left >= t.size()) {
            if (valid == need.size()) return true;

            char d = s[left];
            left++;

            if (need.count(d)) {
                if (window[d] == need[d]) valid--;
                window[d]--;
            }
        }
    }
    return false;
}


//   review
bool checkInclusion(string s1, string s2) {
    unordered_map<char, int> need, window;
    for (char c : s1) need[c]++;
    int left = 0, right = 0;
    int valid = 0;
    while (right < s2.size()) {
        char c = s2[right];
        right++;
        if (need.count(c)) {
            window[c]++;
            if (window[c] == need[c]) valid++;
        }

        if (right - left == s1.size()) {
            if (valid == need.size()) return true;
            char t = s2[left];
            if (need.count(t)) {
                if (window[t] == need[t]) valid--;
                window[t]--;
            }
            left++;
        }
    }
    return false;
}
