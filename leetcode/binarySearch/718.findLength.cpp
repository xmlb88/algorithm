#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// violence
int findLength(vector<int>& A, vector<int>& B) {
    int max_length = 0;
    for (int i = 0; i < A.size(); ++i) {
        for (int j = 0; j < B.size(); ++j) {
            if (A[i] != B[j]) continue;

            int length = 0;
            int li = i, lr = j;
            while (li < A.size() && lr < B.size() && A[li++] == B[lr++]) length++;
            max_length = max(max_length, length);
        }
    }
    return max_length;
}

// dp
int findLength(vector<int>& A, vector<int>& B) {
    int n = A.size(), m = B.size();
    vector<vector<int>> dp(n, vector<int> (m, 0));
    int max_length = 0;

    for (int i = 0; i < m; ++i) {
        if (A[0] == B[i]) dp[0][i] = 1;
    }

    for (int i = 0; i < n; ++i) {
        if (A[i] == B[0]) dp[i][0] = 1;
    }

    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            if (A[i] == B[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = 0;

            max_length = max(max_length, dp[i][j]);
        }
    }

    return max_length;
}

// dp 优化
int findLength(vector<int>& A, vector<int>& B) {
    int n = A.size(), m = B.size();
    vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));

    int max_length = 0;
    for (int i = n - 1; i >= 0; --i) {
        for (int j = m - 1; j >= 0; --j) {
            dp[i][j] = A[i] == A[j] ? dp[i + 1][j + 1] + 1 : 0;
            max_length = max(max_length, dp[i][j]);
        }
    }

    return max_length;
}

// dp 滚动数组优化空间
int findLength(vector<int>& A, vector<int>& B) {
    int n = A.size(), m = B.size();
    vector<int> dp(m + 1, 0);
    int max_length = 0;

    for (int i = 1; i <= n; ++i) {
        for (int j = m; j >= 1; --j) {
            dp[j] = A[i - 1] == B[j - 1] ? dp[j - 1] + 1 : 0;
            max_length = max(max_length, dp[j]);
        }
    }

    return max_length;
}

// 滑动窗口 own thought
// 枚举所有对齐方式，再计算子数组长度


int subArrayLength(vector<int>& A, vector<int>& B, int indexA, int indexB) {
    int max_length = 0, length = 0;
    for (; indexA < A.size() && indexB < B.size(); ++indexA, ++indexB) {
        if (A[indexA] == B[indexB]) {
            ++length;
        } else {
            length = 0;
        }
        max_length = max(max_length, length);
    }
    return max_length;
}

int findLength(vector<int>& A, vector<int>& B) {
    int n = A.size(), m = B.size();
    int max_length = 0;
    for (int i = 0; i < m; ++i) {
        max_length = max(max_length, subArrayLength(A, B, 0, i));
    }

    for (int i = 0; i < n; ++i) {
        max_length = max(max_length, subArrayLength(A, B, i, 0));
    }

    return max_length;
}

// 滑动窗口，copy
int maxLength(vector<int>& A, vector<int>& B, int addA, int addB, int len) {
    int ret = 0, k = 0;
    for (int i = 0; i < len; i++) {
        if (A[addA + i] == B[addB + i]) {
            k++;
        } else {
            k = 0;
        }
        ret = max(ret, k);
    }
    return ret;
}

int findLength(vector<int>& A, vector<int>& B) {
    int n = A.size(), m = B.size();
    int ret = 0;
    for (int i = 0; i < n; i++) {
        int len = min(m, n - i);
        int maxlen = maxLength(A, B, i, 0, len);
        ret = max(ret, maxlen);
    }

    for (int i = 0; i < m; i++) {
        int len = min(n, m - i);
        int maxlen = maxLength(A, B, 0, i, len);
        ret = max(ret, maxlen);
    }

    return ret;
}

// 二分 + 哈希
// TODO:
const int mod = 1000000009;
const int base = 113;

// 快速幂计算x ^ n % mod 的值
long long qPow(long long x, long long n) {
    long long ret = 1;
    while (n) {
        if (n & 1) {
            ret = ret * x % mod;
        }
        x = x * x % mod;
        n >>= 1;
    }
    return ret;
}

bool check(vector<int>& A, vector<int>& B, int len) {
    long long hashA = 0;
    for (int i = 0; i < len; i++) {
        hashA = (hashA * base + A[i]) % mod;
    }
    unordered_set<long long> bucketA;
    bucketA.insert(hashA);
    long long mult = qPow(base, len - 1);
    for (int i = len; i < A.size(); i++) {
        hashA = ((hashA - A[i - len] * mult % mod + mod) % mod * base + A[i]) % mod;
        bucketA.insert(hashA);
    }

    long long hashB = 0;
    for (int i = 0; i < len; i++) {
        hashB = (hashB * base + B[i]) % mod;
    }

    if (bucketA.count(hashB)) return true;

    for (int i = len; i < B.size(); i++) {
        hashB = ((hashB - B[i - len] * mult % mod + mod) % mod * base + B[i]) % mod;
        if (bucketA.count(hashB)) return true;
    }

    return false;
}

int findLength(vector<int>& A, vector<int>& B) {
    int left = 1, right = min(A.size(), B.size()) + 1;
    while (left < right) {
        int mid = left + ((right - left) >> 1);
        if (check(A, B, mid)) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left - 1;
}



// 
const int base = 113;
const int mod = 1000000009;
long long qPow(long long x, long long n) {
    long long ret = 1;
    while (n) {
        if (n & 1) {
            ret = (ret * x) % mod;
        }
        x = x * x % mod;
        n >>= 1;
    }
    return ret;
}

bool check(vector<int>& A, vector<int>& B, int len) {
    long long hashA = 0;
    for (int i = 0; i < len; i++) {
        hashA = (hashA * base + A[i]) % mod;
    }
    unordered_set<long long> bucketA;
    bucketA.insert(hashA);
    long long mult = qPow(base, len - 1);
    for(int i = len; i < A.size(); i++) {
        hashA = ((hashA - A[i - len] * mult % mod + mod) % mod * base + A[i]) % mod;
        bucketA.insert(hashA);
    }

    long long hashB = 0;
    for (int i = 0; i < len; i++) {
        hashB = (hashB * base + B[i]) % mod;
    }

    if (bucketA.count(hashB)) return true;
    for (int i = len; i < B.size(); i++) {
        hashB = ((hashB - B[i - len] * mult % mod + mod) % mod * base + B[i]) % mod;
        if (bucketA.count(hashB)) return true;
    }

    return false;
}

int findLength(vector<int>& A, vector<int>& B) {
    int left = 1, right = min(A.size(), B.size()) + 1;
    while (left < right) {
        int mid = (left + right) >> 1;
        if (check(A, B, mid)) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left - 1;
}