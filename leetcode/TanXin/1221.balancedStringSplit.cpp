#include <iostream>
#include <string>
#include <vector>
using namespace std;

int balancedStringSplit(string s) {
    int count = 0;
    int L_count = 0, R_count = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'L') {
            ++L_count;
        } else if (s[i] == 'R') {
            ++R_count;
        }

        if (L_count == R_count) {
            ++count;
        }
    }
    return count;
}

int balancedStringSplit(string s) {
    int count = 0, t = 0;
    for (auto c : s) {
        if (c == 'L') ++t;
        else --t;

        if (t == 0) ++count;
    }
    return count;
}