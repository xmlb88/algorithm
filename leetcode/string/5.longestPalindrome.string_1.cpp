#include<iostream>
#include<string>
using namespace std;

string longestPalindrome(string s) {
    string res;
    for (int i = 0; i < s.length(); i++) {
        // s[i]为中心的最长回文子串
        string s1 = palindrome(s, i, i);
        // s[i]和s[i + 1]为中心的最长回文子串
        string s2 = palindrome(s, i, i + 1);
        // res = longest(res, s1, s2)
        res = res.length() > s1.length() ? res : s1;
        res = res.length() > s2.length() ? res : s2;
    }
    return res;
}

string palindrome(string& s, int l, int r) {
    while (l >= 0 && r < s.length() && s[l] == s[r]) {
        l--; r++;
    }
    return s.substr(l + 1, r - l - 1);
}


string longestPalindrome(string s) {
    string ans;
    for (int i = 0; i < s.length(); i++) {
        string s1 = palindrome(s, i, i);
        string s2 = palindrome(s, i, i + 1);
        ans = ans.length() < s1.length() ? s1 : ans;
        ans = ans.length() < s2.length() ? s2 : ans;
    }
    return ans;
}

string palindrome(string s, int l, int r) {
    while (l >= 0 && r < s.length() && s[l] == s[r]) {
        l--; r++;
    }

    return s.substr(l + 1, r - l - 1);
}


// review 2021年1月8日17:29:06
// 暴力方法
string longestPalindrome(string s) {
    int n = s.size();
    if (n <= 1) return s;
    string res;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (j - i + 1 > res.size() && valid(s, i, j)) {
                res = s.substr(i, j - i + 1);
            }
        }
    }
    return res;
}

bool valid(string& s, int left, int right) {
    while (left < right) {
        if (s[left] != s[right]) return false;
        left++; right--;
    }
    return true;
}

// dp动态规划
string longestPalingrome(string s) {
    
}