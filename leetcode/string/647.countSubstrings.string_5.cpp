#include <iostream>
#include <vector>
#include <string>
using namespace std;

int countSubstrings(string s) {
    int n = s.length();
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += countSubstring(s, i, i);
        sum += countSubstring(s, i, i + 1);
    }

    return sum;
}

int countSubstring(string s, int l, int r) {
    int count = 0;
    while (l >= 0 && r < s.length() && s[l] == s[r]) {
        count++;
        l--;r++;
    }
    return count;
}