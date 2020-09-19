#include<iostream>
#include<string>
using namespace std;

string longestPalindrome(string s) {
    string res;
    for (int i = 0; i < s.length(); i++) {
        // s[i]Ϊ���ĵ�������Ӵ�
        string s1 = palindrome(s, i, i);
        // s[i]��s[i + 1]Ϊ���ĵ�������Ӵ�
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

