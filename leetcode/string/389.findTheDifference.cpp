#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

char findTheDifference(string s, string t) {
    unordered_map<char, int> m;
    for (char c : s) {
        m[c]++;
    }

    for (char c : t) {
        if (m[c] == 0) return c;
        m[c]--;
    }
    
    return '1';
}

// 求和
char findTheDifference(string s, string t) {
    int as = 0, at = 0;
    for (char c : s) {
        as += c;
    }
    for (char c : t) {
        at += c;
    }
    return at - as;
}

// 位运算
char findTheDifference(string s, string t) {
    int ret = 0;
    for (char c : s) {
        ret ^= c;
    }
    for (char c : t) {
        ret ^= c;
    }
    return ret;
}