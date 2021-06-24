#include <iostream>
#include <string>
using namespace std;

/**
 * The read4 API is defined in the parent class Reader4.
 *      int read4(char *buf4);
 */

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */

    int read(char *buf, int n) {
        if (n == 0) return 0;
        for (int len = 0; len < n;) {
            int add_len = read4(buf + len);
            if (add_len == 0) {
                return len;
            }
            len += add_len;
        }
        return n;
    }
}


int read(char* buf, int n) {
    int res = 0;
    for (int i = 0; i < n; i += 4) {
        int count = read4(buf + i);
        res += min(count, n - i);
    }
    return res;
}

int read(char* buf, int n) {
    int res = 0;
    for (int i = 0; i <= n / 4; ++i) {
        int count = read4(buf + res);
        if (count == 0) break;
        res += count;
    }
    return min(res, n);
}