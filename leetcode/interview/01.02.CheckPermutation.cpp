#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

// 排序后比较是否相同
bool CheckPermutation(string s1, string s2) {
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    return s1 == s2;
}

// 检查字符数是否相同，类似散列表的数组
bool CheckPermutation(string s1, string s2) {
    if (s1.length() != s2.length()) return false;

    vector<int> letters(128, 0);
    for (int i = 0; i < s1.length(); i++) {
        letters[s1[i]]++;
    }

    for (int i = 0; i < s2.length(); i++) {
        letters[s2[i]]--;
        if (letters[s2[i]] < 0) return false;
    }

    return true;
}