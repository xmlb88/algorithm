#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> findAnagrams(string s, string p) {
    vector<int> need(26, 0), window(26, 0);
    int n = p.size(), m = s.size();
    vector<int> res;

    for (char c : p) {
        need[c - 'a']++;
    }

    int left = 0, right = 0;
    while (right < m) {
        window[s[right] - 'a']++;
        right++;

        if (right - left == n) {
            if (need == window) {
                res.push_back(left);
            }
            window[s[left] - 'a']--;
            left++;
        }
    }
    return res;
}