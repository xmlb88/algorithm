#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

int firstUniqChar(string s) {
    vector<int> map(26, 0);
    for (int i = 0; i < s.length(); i++) {
        map[s[i] - 'a']++;
    }

    for (int i = 0; i < s.length(); i++) {
        if (map[s[i] - 'a'] == 1) return i;
    }

    return -1;
}

int firstUniqChar(string s) {
    unordered_map<int, int> position;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        if (position.count(s[i])) {
            position[s[i]] = -1;
        } else {
            position[s[i]] = i;
        }
    }
    int first = n;
    for (auto [_, pos] : position) {
        if (pos != -1 && pos < first) {
            first = pos;
        }
    }
    if (first == n) first = -1;
    return first;
}