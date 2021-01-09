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
string longestPalindrome(string s) {
    int n = s.size();
    if (n < 2) return s;
    vector<vector<bool>> dp(n, vector<bool> (n, true)); // 初始化为true
    int begin = 0, maxlen = 1;
    
    for (int i = n - 2; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            if (s[i] == s[j]) {
                if (j - i < 3) dp[i][j] = true;
                else dp[i][j] = dp[i + 1][j - 1];
            } else dp[i][j] = false;

            if (dp[i][j] && j - i + 1 > maxlen) {
                begin = i;
                maxlen = j - i + 1;
            }
        }
    }

    return s.substr(begin, maxlen);
}

string longestPalindrome(string s) {
    int n = s.size();
    if (n < 2) return s;
    vector<vector<bool>> dp(n, vector<bool> (n, false));

    int begin = 0, maxlen = 1;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i; j < n; j++) {
            if (s[i] == s[j]) {
                if (j - i < 3) dp[i][j] = true;
                else dp[i][j] = dp[i + 1][j - 1];
            }

            if (dp[i][j] && j - i + 1 > maxlen) {
                begin = i;
                maxlen = j - i + 1;
            }
        }
    }
    return s.substr(begin, maxlen);
}

/*
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) dp[i][j]从左到右，从上到下

    for (int j = 0; j < n; j++)
        for (int i = 0; i < n; i++) dp[i][j]从上到下，从左到右

*/

// 中心扩展法
string longestPalindrome(string s) {
    int n = s.size();
    if (n < 2) return s;
    string res;

    // 遍历每个字符作为中心
    for (int i = 0; i < n; i++) {
        string s1 = palindrome(s, i, i);
        string s2 = palindrome(s, i, i + 1);
        res = s1.size() > res.size() ? s1 : res;
        res = s2.size() > res.size() ? s2 : res;
    }
    return res;
}

string palindrome(const string& s, int l, int r) {
    while (l >= 0 && r < s.size() && s[l] == s[r]) {
        l--; r++;
    }
    // (r - 1) - (l + 1) + 1
    return s.substr(l + 1, r - l - 1);
}

// manacher
// step1
string longestPalindrome(string s) {
    int n = s.size();
    if (n < 2) return s;

    string str = "#";
    for (int i = 0; i < s.size(); i++) {
        str += s[i];
        str += "#";
    }

    int sSize = 2 * n + 1;
    int maxlen = 1, start = 0;

    for (int i = 0; i < sSize; i++) {
        int curLen = palindrome(str, i);
        if (curLen > maxlen) {
            maxlen = curLen;
            start = (i - maxlen) / 2;
        }
    }
    return s.substr(start, maxlen);
}

int palindrome(string& s, int center) {
    int len = s.size();
    int i = center - 1;
    int j = center + 1;
    int step = 0;
    while (i >= 0 && j < len && s[i] == s[j]) {
        i--;
        j++;
        step++;
    }
    return step;
}