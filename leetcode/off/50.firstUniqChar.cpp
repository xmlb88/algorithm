#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

char firstUniqChar(string s) {
    if (s.empty()) return ' ';
    vector<int> countChar(26, 0);
    for (int i = 0; i < s.size(); i++) {
        countChar[s[i] - 'a']++;
    }
    for (int i = 0; i < s.size(); i++) {
        if (countChar[s[i] - 'a'] == 1) return s[i];
    }
    return ' ';
}