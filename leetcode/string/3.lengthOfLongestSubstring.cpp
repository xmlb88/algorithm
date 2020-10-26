#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int lengthOfLongestSubstring(string s) {
    int length = 0;
    int i = 0, j = 0;
    unordered_map<char, int> window;
    while (i < s.size() && j < s.size()) {
        while (!window.count(s[j])) {
            j++;
            window[s[j]]++;
        }
    }
}