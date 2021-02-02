#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

int lengthOfLongestSubstring(string s) {
    int n = s.size();
    int left = 0, right = 0;
    unordered_map<char, int> mp;
    int res = 0;
    while (right < n) {
        char c = s[right];
        mp[c]++;
        right++;

        while (mp[c] > 1) {
            char t = s[left];
            mp[t]--;
            left++;
        }
        res = max(res, right - left);
    }
    return res;
}