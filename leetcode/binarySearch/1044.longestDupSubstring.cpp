#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;
// abcdefg
// WA
string check(string& s, int len) {
    unordered_set<string> str;
    for (int i = 0; i <= s.size() - len; ++i) {
        if (str.find(s.substr(i, len)) != str.end()) {
            return s.substr(i, len);
        }
        str.insert(s.substr(i, len));
    }
    return "";
}

string longestDupSubstring(string s) {
    int left = 0, right = s.size();
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (check(s, mid) == "") {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return check(s, left - 1);
}

int main() {
    string s = "banana";
    cout << longestDupSubstring(s) << endl;
}

// TODO: