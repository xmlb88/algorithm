#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

bool checkInclusion(string s1, string s2) {
    // vector<int> need(26, 0), window(26, 0);
    unordered_map<char, int> need, window;
    int n = s1.size(), m = s2.size();
    for (char c : s1)
        need[c]++;

    int left = 0, right = 0;
    int valid = 0;
    while (right < m) {
        char c = s2[right];
        if (need.count(c)) {
            window[c]++;
            if (window[c] == need[c]) valid++;
        }
        right++;

        while (right - left >= n) {
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

bool checkInclusion(string s1, string s2) {
    vector<int> need(26, 0), window(26, 0);
    for (char c : s1) {
        need[c - 'a']++;
    }

    int left = 0, right = 0;
    while (right < s2.size()) {
        window[s2[right] - 'a']++;
        right++;

        if (right - left == s1.size()) {
            if (need == window) return true;

            window[s2[left] - 'a']--;
            left++;
        }
    }
    return false;
}

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

// review 2021年3月3日
bool checkInclusion(string s1, string s2) {
    vector<int> window(26, 0), need(26, 0);
    for (char c : s1) {
        need[c - 'a']++;
    }

    int left = 0, right = 0;
    while (right < s2.size()) {
        window[s2[right] - 'a']++;
        right++;

        if (right - left == s1.size()) {
            if (window == need) return true;
            window[s2[left] - 'a']--;
            left++;
        }
    }
    return false;
}

// 优化
bool checkInclusion(string s1, string s2) {
    int n = s1.size(), m = s2.size();
    if (n > m) return false;
    vector<int> window(26, 0);
    for (int i = 0; i < n; ++i) {
        window[s1[i] - 'a']--;
        window[s2[i] - 'a']++;
    }

    int diff = 0;
    for (int c : window) {
        if (c != 0) ++diff;
    }

    if (diff == 0) return true;
    for (int i = n; i < m; ++i) {
        int x = s2[i] - 'a', y = s2[i - n] - 'a';
        if (x == y) {
            continue;
        }

        if (window[x] == 0) ++diff;
        ++window[x];
        if (window[x] == 0) --diff;
        if (window[y] == 0) ++diff;
        --window[y];
        if (window[y] == 0) --diff;

        if (diff == 0) return true;
    }
    return false;
}

// another way
bool checkInclusion(string s1, string s2) {
    int n = s1.size(), m = s2.size();
    if (n > m) return false;

    vector<int> cnt(26);
    for (int i = 0; i < n; ++i) {
        --cnt[s1[i] - 'a'];
    }
    
    int left = 0, right = 0;
    while (right < m) {
        int x = s2[right] - 'a';
        ++cnt[x];
        ++right;
        while (cnt[x] > 0) {
            --cnt[s2[left] - 'a'];
            ++left;
        }
        if (right - left == n) return true;
    }
    return false;

    // int left = 0, right = 0;
    // for (; right < m; ++right) {
    //     int x = s2[right] - 'a';
    //     ++cnt[x];
    //     while (cnt[x] > 0) {
    //         --cnt[s2[left] - 'a'];
    //         ++left;
    //     }

    //     if (right - left + 1 == n) {
    //         return true;
    //     }
    // }
    // return false;
}