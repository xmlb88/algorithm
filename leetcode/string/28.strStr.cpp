#include <iostream>
#include <string>
using namespace std;

int strStr(string haystack, string needle) {
    return haystack.find(needle);
}

// hello ll
int strStr(string haystack, string needle) {
    if (needle.empty()) return 0;
    int n = haystack.size(), m = needle.size();
    if (n < m) return -1;
    for (int i = 0; i <= n - m; ++i) {
        if (haystack.substr(i, m) == needle) {
            return i;
        }
    }
    return -1;
}

int strStr(string haystack, string needle) {
    int n = haystack.size(), m = needle.size();
    for (int i = 0; i + m <= n; i++) {
        bool flag = true;
        for (int j = 0; j < m; j++) {
            if (haystack[i + j] != needle[j]) {
                flag = false;
                break;
            }
        }

        if (flag) {
            return i;
        }
    }
    return -1;
}

// TODO:
// TODO: