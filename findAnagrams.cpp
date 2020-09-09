#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

vector<int> findAnagrams(string s, string t) {
    int start = 0;
    int left = 0, right = 0;
    vector<int> result;

    unordered_map<char, int> needs;
    unordered_map<char, int> window;

    for (char c : t) needs[c]++;
    int match = 0;

    while (right < s.size()) {
        char c = s[right];
        if (needs.count(c)) {
            window[c]++;
            if (window[c] == needs[c]) match++;
        }
        right++;
        
        while (match == needs.size()) {
            if (right - left == t.size()) {
                vector.push_back(left);
            }

            char c2 = s[left];
            if (needs.count(c2)) {
                window[c2]--;
                if (window[c2] < needs[c2]) match--;
            }
            left++;
        }
    }
    return res;
}