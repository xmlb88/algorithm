#include <iostream>
#include <string>
#include <vector>
using namespace std;

// int strStr(string haystack, string needle) {
//     return haystack.find(needle);
// }

// // hello ll
// int strStr(string haystack, string needle) {
//     if (needle.empty()) return 0;
//     int n = haystack.size(), m = needle.size();
//     if (n < m) return -1;
//     for (int i = 0; i <= n - m; ++i) {
//         if (haystack.substr(i, m) == needle) {
//             return i;
//         }
//     }
//     return -1;
// }

// int strStr(string haystack, string needle) {
//     int n = haystack.size(), m = needle.size();
//     for (int i = 0; i + m <= n; i++) {
//         bool flag = true;
//         for (int j = 0; j < m; j++) {
//             if (haystack[i + j] != needle[j]) {
//                 flag = false;
//                 break;
//             }
//         }

//         if (flag) {
//             return i;
//         }
//     }
//     return -1;
// }

// // TODO:
// // TODO:

// // ÆÓËØÆ¥Åä
// int strStr(string haystack, string needle) {
//     int i = 0, j = 0;
//     int h_len = haystack.size(), n_len = needle.size();
//     while (i < h_len && j < n_len) {
//         if (haystack[i] == needle[j]) {
//             ++i;
//             ++j;
//         } else {
//             i = i - j + 1;
//             j = 0;
//         }
//     }

//     if (j == n_len) return i - j;
//     return -1;
// }

// KMP
void getNext(string p, vector<int>& next) {
    int p_len = p.size();
    int i = 0, j = -1;
    next[0] = -1;

    while (i < p_len) {
        if (j == -1 || p[i] == p[j]) {
            ++i;
            ++j;
            next[i] = j;
        } else {
            j = next[j];
        }
    }
}

int strStr(string haystack, string needle) {
    int i = 0, j = 0;
    int h_len = haystack.size(), n_len = needle.size();
    vector<int> next(n_len + 1, 0);
    getNext(needle, next);

    while (i < h_len && j < n_len) {
        if (j == -1 || haystack[i] == needle[j]) {
            ++i;
            ++j;
        } else j = next[j];
    }

    if (j == n_len) return i - j;
    return -1;
}

int main() {
    string haystack = "hello", needle = "ll";
    cout << strStr(haystack, needle) << endl;
}


// https://leetcode-cn.com/problems/implement-strstr/solution/shua-chuan-lc-shuang-bai-po-su-jie-fa-km-tb86/

int strStr(string s, string p) {
    int n = s.size(), m = p.size();
    if (m == 0) return 0;

    s.insert(s.begin(), ' ');
    p.insert(p.begin(), ' ');

    vector<int> next(m + 1);

    for (int i = 2, j = 0; i <= m; ++i) {
        while (j && p[i] !=  p[j + 1]) j = next[j];
        if (p[i] == p[j + 1]) ++j;
        next[i] = j;
    }

    for (int i = 0, j = 0; i <= n; ++i) {
        while (j && s[i] != p[j + 1]) j = next[j];
        if (s[i] == p[j + 1]) j++;
        if (j == m) return i - m;
    }

    return -1;
}